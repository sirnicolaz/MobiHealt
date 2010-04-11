#include "ImageItemWidget.h"
#include "buttonlabel.h"
#include "ImageWidget.h"
#include "NoteWidget.h"
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QVBoxLayout>

ImageItemWidget::ImageItemWidget(QString *image, QWidget *parent)
    : QWidget(parent)
{
	/* create the GUI objects */
	viewImageButton = new ButtonLabel(QPixmap(":/icons/viewImageButton.png"), QPixmap(":/icons/viewImageButtonPushed.png"), this);
	connect(viewImageButton, SIGNAL(released()), this, SLOT(viewImageSlot()));
    viewNoteButton = new ButtonLabel(QPixmap(":/icons/viewImageNoteButton.png"), QPixmap(":/icons/viewImageNoteButtonPushed.png"), this);
    connect(viewNoteButton, SIGNAL(released()), this, SLOT(viewNoteSlot()));
    imagePreview = new QLabel(this);
    imagePreview->setPixmap(QPixmap(":/icons/testPreview.png"));
    
    /* initialize image item object */
    imageItem = image;
    
    /* layout operations */
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->setContentsMargins(0,0,0,0);
    QVBoxLayout *buttonsLayout = new QVBoxLayout();
    
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(viewImageButton);
    buttonsLayout->addWidget(viewNoteButton);
    buttonsLayout->addStretch();
    
    mainLayout->addWidget(imagePreview);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonsLayout);
    
    
    setLayout(mainLayout);
	
}

void ImageItemWidget::viewNoteSlot()
{
	QString title("Nota Immagine");
	QString text("Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
	NoteWidget *widget = new NoteWidget(title, text);
	widget->setAttribute(Qt::WA_DeleteOnClose);
	widget->showFullScreen();
}

void ImageItemWidget::viewImageSlot()
{
	/* TODO: get the correct image using web method!! */
	/* test image */
	QString base64Image("image");
	ImageWidget *widget = new ImageWidget(base64Image);
	widget->setAttribute(Qt::WA_DeleteOnClose);
	widget->showFullScreen();
}

ImageItemWidget::~ImageItemWidget()
{

}
