#include "MobiError.h"
#include "MobiHealth.h"
#include "buttonlabel.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QPixmap>

MobiError::MobiError(QWidget *parent)
    : QWidget(0)
{
	ui.setupUi(this);
	setBackgroundImage();
	setContentsMargins(0,0,0,0);
	
	/* initialize the parent widget reference */
	this->parent = dynamic_cast<MobiHealth*>(parent);
	
	ButtonLabel *quitButton = new ButtonLabel(QPixmap(":/icons/quitButton.png"), QPixmap(":/icons/quitButtonPushed.png"), this);
	connect(quitButton, SIGNAL(released()), this, SLOT(quitButtonSlot()));

	QVBoxLayout *layout = new QVBoxLayout();
	layout->setContentsMargins(0,0,0,0);
	layout->setAlignment(Qt::AlignTop);
	
	QHBoxLayout *headerLayout = new QHBoxLayout();
	headerLayout->setContentsMargins(13, 15, 13, 0);
	
	headerLayout->addStretch();
	headerLayout->addWidget(quitButton);
	
	layout->addLayout(headerLayout);
	layout->addStretch();
	
	setLayout(layout);
	
}

void MobiError::setBackgroundImage()
{
	QPalette p = palette();
	QPixmap pixmap(":/icons/errorBg.png");
	p.setBrush(QPalette::Background,  pixmap);
	setPalette(p);
}

void MobiError::quitButtonSlot()
{
	/* activate the parent widget */
	parent->activateWindow();
		
	/* close the result form */
	this->close();	
}

MobiError::~MobiError()
{

}
