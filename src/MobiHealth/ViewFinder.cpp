#include "ViewFinder.h"
#include <QPainter>
#include <QPixmap>
#include <QBrush>

/* viewfinder widget constructor */
ViewFinder::ViewFinder(QWidget *parent)
	: QWidget(parent)
{
	
}

ViewFinder::~ViewFinder()
{
	
}

/* update the current frame */
void ViewFinder::updateFrame(QPixmap aFrame)
{
	frame = aFrame;
}

/* redraw the widget */
void ViewFinder::paintEvent(QPaintEvent *event)
{
	QPainter p(this);
	p.drawPixmap(0,0,frame);
}
