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

    Q_OBJECT

public:
    startview();

    QLayout* createButtonsLayout();
public slots:
    void createPie();
    void createLine();
    void createBar();
    void createSpline();
    void createScatter();
};


#endif // STARTVIEW_H
