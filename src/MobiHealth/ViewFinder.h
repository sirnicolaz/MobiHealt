#ifndef VIEWFINDER_H
#define VIEWFINDER_H

#include <QtGui/QWidget>

class QPixmap;
class QPaintEvent;

class ViewFinder : public QWidget
{
    Q_OBJECT

public:
	ViewFinder(QWidget *parent = 0);
    ~ViewFinder();
    
    /* update the current frame */
    void updateFrame(QPixmap frame);
    
    /* from base class */
    void ViewFinder::paintEvent(QPaintEvent *event);
    
private:
    /* current frame */
    QPixmap frame;
};

#endif // VIEWFINDER_H
