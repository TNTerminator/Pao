#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QVBoxLayout>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDockWidget>
#include <QObject>
#include "userinputs.h"
class startview :public QMainWindow{
public:
    startview();

    QLayout* createButtonsLayout();
public slots:
    void ChangeChart(int);
};


#endif // STARTVIEW_H
