#ifndef __CAMERAOBSERVER_H__
#define __CAMERAOBSERVER_H__

//#include <coecntrl.h>
//#include <fbs.h>

/* wrapper inclusion */
#include "cameraengine.h"
#include "cameraengineobserver.h"

/* forward class declaration */
class ViewFinder;
class CameraWidget;

class CameraObserver : public MCameraEngineObserver
{
public:
	// 2-phase constructors and distructor
	static CameraObserver* NewL( const TRect& aRect , ViewFinder* viewFinder, CameraWidget* parent );
	static CameraObserver* NewLC( const TRect& aRect , ViewFinder* viewFinder, CameraWidget* parent );
	virtual ~CameraObserver();
	
	/* adjust digital zoom (true = in) */
	void zoom(TBool);
	
	/* start focusing to capture image */
	void startFocusing();
	
private: 
	/* private constructors */
	void ConstructL( const TRect& aRect , ViewFinder* viewFinder, CameraWidget* parent );
	CameraObserver();
	
	/* method from wrapper observer */
	/* invoked after ReserveAndPowerOn(), when camera is ready to be used */
	void MceoCameraReady();
	/* invoked periodically when a new frame is ready from camera (to view finder) */
	void MceoViewFinderFrameReady( CFbsBitmap& aFrame ); 
	/* invoked when picture is focused ( after StartFocusL() ) */
	void MceoFocusComplete();
	/* invoked after CaptureL(), when camera finish his job */
	void MceoCapturedDataReady( TDesC8* aData );
	void MceoCapturedBitmapReady( CFbsBitmap* aBitmap );
	/* invoked to handle observer and engine error (TODO!) */
	void MceoHandleError( TCameraEngineError aErrorType, TInt aError );
	void MceoHandleOtherEvent( const TECAMEvent& /*aEvent*/ );
	
	/* save captured picture to FS */
	void savePicture( TDesC8* aData );
	
    /* data fields */
	/* reference to the camera engine wrapper */
	CCameraEngine* iCameraWrapper;
	/* view finder and capture size */
	TSize iViewFinderSize;
	TSize iCaptureSize;
	/* reference to the view finder widget */
	ViewFinder* viewFinder;
	/* reference to the camera widget object (parent) */
	CameraWidget* parent;

    // Is new picture focused whit camera shutter key
    //TBool iCameraShutterFocusing;

    /* captured image data */
    HBufC8* iData;
};

#endif // __CAMERAOBSERVER_H__
