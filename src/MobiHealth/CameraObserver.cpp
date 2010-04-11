#include "coemain.h"
#include "eikon.hrh"
#include "aknutils.h"
#include "PathInfo.h"
#include "f32file.h"
#include "BAUTILS.H"
#include "CameraObserver.h"
#include "CameraWidget.h"
#include "ViewFinder.h"
#include <eikenv.h>
#include <eikappui.h>
#include <aknenv.h>
#include <aknappui.h>

CameraObserver* CameraObserver::NewL( const TRect& aRect , ViewFinder* viewFinder, CameraWidget* parent )
{
    CameraObserver* self = CameraObserver::NewLC(aRect, viewFinder, parent);
    CleanupStack::Pop(self);
    return self;
}

CameraObserver* CameraObserver::NewLC( const TRect& aRect , ViewFinder* viewFinder, CameraWidget* parent )
{
	CameraObserver* self = new (ELeave) CameraObserver;
    CleanupStack::PushL(self);
    self->ConstructL(aRect, viewFinder, parent);
    return self;
}

void CameraObserver::ConstructL( const TRect& aRect , ViewFinder* viewFinder, CameraWidget* parent )
{
	/* if there is a camera available, create a new camera engine for it */
	TInt camErr(KErrNotSupported);
	if(CCameraEngine::CamerasAvailable() > 0)
	{
		TRAP(camErr, iCameraWrapper = CCameraEngine::NewL(0,0,this));
	}
	else
	{
		// ERROR HANDLING
		User::Leave(camErr);
	}
	
	/* init data fields */
	iData=0;
	this->parent = parent;
	this->viewFinder = viewFinder;
	iCaptureSize = TSize(2048,1536);
	//iCaptureSize = TSize(480,640);
	iViewFinderSize = TSize(aRect.Size().iWidth, aRect.Size().iHeight);
	
	/* if no error, reserve and power on the camera */
	if(camErr == KErrNone)
	{
		iCameraWrapper->ReserveAndPowerOn();
		/* when finish invoke MceoCameraReady() */
	}
	else
	{
		// ERROR HANDLING
		User::Leave(camErr);
	}
}

CameraObserver::CameraObserver()
{
	// NOTHING TO DO BECAUSE WE USE 2-PHASE CONSTRUCTOR
}

void CameraObserver::MceoCameraReady()
{
	/* if engine is in idle state (doing nothing) */
	if (iCameraWrapper->State() == CCameraEngine::EEngineIdle)
	{
		/*
		CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
	    TRAPD(error,
	    if (appUi) appUi->SetOrientationL(CAknAppUi::EAppUiOrientationLandscape);
	    );
		*/
	
		/* prepare the camera to capture image of iCapturSize size (JPEG/Exif format) */
		TRAPD(err,iCameraWrapper->PrepareL(iCaptureSize));
		if (err)
		{
			// ERROR HANDLING
			return;
		}
		
		/* Start viewfinder. Viewfinder pictures starts coming into MceoViewFinderFrameReady(); */
		/* StartViewFinderL(size) periodically send frame to MceoViewFinderFrameReady(bitmap) */
		TRAPD(err2,iCameraWrapper->StartViewFinderL(iViewFinderSize)); 
		if (err2)
		{
			// ERROR HANDLING
			return;
		}
	}
}

void CameraObserver::MceoViewFinderFrameReady( CFbsBitmap& aFrame )
{
	/* update viewfinder widget */
	viewFinder->updateFrame( QPixmap::fromSymbianCFbsBitmap(&aFrame) ); // maybe use reference is better
	viewFinder->repaint();
	
	/* release view finder buffer */
	if (iCameraWrapper) 
		iCameraWrapper->ReleaseViewFinderBuffer();
}

void CameraObserver::MceoFocusComplete()
{
	/* image focused, ready to capture. Stop viewfinder and capture picture */
	iCameraWrapper->StopViewFinder();
	TRAPD(err,iCameraWrapper->CaptureL());
	if (err)
	{
		// ERROR HANDLING
	}
}

void CameraObserver::MceoCapturedDataReady( TDesC8* aData )
{
	/* free memory */
	if (iData)
	{
		delete iData; 
		iData = NULL;
	}
	iData = aData->Alloc();
	
	/* release image buffer */
	if (iCameraWrapper)
		iCameraWrapper->ReleaseImageBuffer();
	
	/* save picture data to FS */
	savePicture(iData);
	
	/* release and power off the camera here */
	iCameraWrapper->ReleaseAndPowerOff();
	/* picture saved, notify CameraWidget so it can proceed (pass to next step and quit) */
	parent->pictureSaved();
}

void CameraObserver::MceoCapturedBitmapReady( CFbsBitmap* aBitmap )
{
	// NOTHING TO DO, ONLY RELEASE IMAGE BUFFER
	if (iCameraWrapper)
		iCameraWrapper->ReleaseImageBuffer();
}

void CameraObserver::MceoHandleError( TCameraEngineError aErrorType, TInt aError )
{
	// ERROR HANDLING!!!
}

void CameraObserver::MceoHandleOtherEvent( const TECAMEvent& /*aEvent*/ )
{
	// NOTHING TO DO
}

void CameraObserver::savePicture(TDesC8* aData)
{
	/* Create path for filename */
	TFileName path = PathInfo::PhoneMemoryRootPath(); 
	//path.Append(PathInfo::ImagesPath());
	
	/* Ensure that path exists */
	//BaflUtils::EnsurePathExistsL(CEikonEnv::Static()->FsSession(),path);

	/* Get next free filename for the image */
	TFileName fileToSave;
	TBool fileExists = ETrue;
	for (TInt i=1 ; i<100 ; i++) // TODO: fix i<100!!
	{
		fileToSave.Copy(path);
		fileToSave.AppendNum(i);
		fileToSave.Append(_L(".jpg"));
		fileExists = BaflUtils::FileExists(CEikonEnv::Static()->FsSession(),fileToSave);
		if (!fileExists)
		{
			break;
		}
	}

	/* Save file */
	if (!fileExists)
	{
		RFile file;
		TInt err = file.Create(CEikonEnv::Static()->FsSession(),fileToSave,EFileWrite);
		if (!err)
		{
			file.Write(*aData);
			file.Close();
		}
		else
		{
			// ERROR HANDLING
		}
	}
	else
	{
		// ERROR HANDLING
	}
}

void CameraObserver::startFocusing()
{
	/* if camera engine is in view finding state (so camera is capturing picture) */
	if (iCameraWrapper && iCameraWrapper->State() == CCameraEngine::EEngineViewFinding)
	{
		/* check if autofocus is supported */
		if (!iCameraWrapper->IsAutoFocusSupported())
		{
			/* no autofocus supported, so? */
		/*
			iCameraWrapper->StopViewFinder();
			TRAPD(err,iCameraWrapper->CaptureL()); //invoked only without focus
			if (err)
			{
				// ERROR HANDLING
			}
		*/
		}
		else
		{
			/* focusing supported. Start focusing */
			iCameraWrapper->StartFocusL();
			/* when complete, invoke MceoFocusComplete() */
		}
	}
}

void CameraObserver::zoom(TBool zoomType)
{
	iCameraWrapper->AdjustDigitalZoom(zoomType);
}

CameraObserver::~CameraObserver()
{
	/* free memory and release and power off camera */
	if (iCameraWrapper)
	{
		iCameraWrapper->ReleaseAndPowerOff();
		delete iCameraWrapper;
	}
	if (iData)
	{
		delete iData;
	}
	/*
	CAknAppUi* appUi = dynamic_cast<CAknAppUi*> (CEikonEnv::Static()->AppUi());
	TRAPD(error,
	if (appUi) appUi->SetOrientationL(CAknAppUi::EAppUiOrientationLandscape);
	);*/
}
