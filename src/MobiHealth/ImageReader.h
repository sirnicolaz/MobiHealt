#include "e32base.h"
#include "coecntrl.h"
#include "w32std.h"
#include "e32std.h"
#include "cntdef.h"
#include "cntdb.h"
#include "ImageConversion.h"
 
class CFbsBitmap;
 
class ImageReader : public CActive
{
public:
    ImageReader();
    void ConstructL(const TDesC& aFileName);
    ~ImageReader();
public:
    CFbsBitmap* Bitmap();
protected:
	void DoCancel();
	void RunL();
	
private:
	CImageDecoder* iImageDecoder;
	CFbsBitmap* iFrame;
	TFileName iImageName;
};
