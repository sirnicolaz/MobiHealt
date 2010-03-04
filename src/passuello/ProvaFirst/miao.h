#ifndef MIAO_H
#define MIAO_H

#include <QtGui/QWidget>
#include "ui_miao.h"

class miao : public QWidget
{
    Q_OBJECT

public:
    miao(QWidget *parent = 0);
    ~miao();

private:
    Ui::miaoClass ui;
};

#endif // MIAO_H
