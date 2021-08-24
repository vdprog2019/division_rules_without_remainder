#pragma once

#include <QtWidgets/QWidget>
#include "ui_price_proj_qt.h"
#include <qstring.h>
#include <vector>
#include <string>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistview.h>
#include <qmessagebox.h>
#include <qdebug.h>
#include <qtextcodec.h>
#include <stdio.h>
#include <sstream>
#include <iomanip> 
#include <qcombobox.h>
class price_proj_qt : public QWidget
{
    Q_OBJECT

public:
    price_proj_qt(QWidget *parent = Q_NULLPTR);
    

public slots:
    void create_price();

protected:
    QString f_1;
    QString f_2;
    QString f_3;
    QString res;
    int pr = 123;
    int f_e = 3;
    int s_e = 23;

    int pr_2 = 123;
    int f_e_2 = 6;
    int s_e_2 = 98;

    int pr_3 = 123;
    int f_e_3 = 5;
    int s_e_3 = 75;

private:
    Ui::price_proj_qtClass ui;
};
