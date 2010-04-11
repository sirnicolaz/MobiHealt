#include "cntfield.h"
#include "cntdef.h"
#include "cntitem.h"
#include "cntfldst.h"
#include "cntdb.h"
#include "COEMAIN.H"
#include "APMREC.H"
#include "APGCLI.H"
#include "ImageReader.h"
 
ImageReader::ImageReader()
:CActive(0)
    {
    }
 
ImageReader::~ImageReader()
{
	Cancel();
	delete iFrame;
    delete iImageDecoder;
}

void ImageReader::ConstructL(const TDesC& aFileName)
{
	CActiveScheduler::Add(this);
	iImageName.Copy(aFileName);
	TBuf8<255> ImageType;
 
	if(iImageName.Length())
	{		
		iImageDecoder = CImageDecoder::FileNewL(CCoeEnv::Static()->FsSession(),aFileName);
		delete iFrame;
		iFrame = NULL;
		iFrame = new(ELeave)CFbsBitmap();
		iFrame->Create(iImageDecoder->FrameInfo(0).iOverallSizeInPixels,iImageDecoder->FrameInfo(0).iFrameDisplayMode);
 
		iImageDecoder->Convert(&iStatus,*iFrame,0);
		SetActive();
	}
	else
	{
		TRequestStatus* status=&iStatus;
		User::RequestComplete(status, KErrNotSupported);
		SetActive();
	}
}
 
void ImageReader::DoCancel()
{
	iImageDecoder->Cancel();
}
 
CFbsBitmap* ImageReader::Bitmap()
{
	return iFrame;
}
 
void ImageReader::RunL()
{
	
}
