#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QVBoxLayout>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDockWidget>
#include <QObject>
#include <QButtonGroup>
#include <QList>
#include <QGroupBox>

#include "basechart.h"
#include "userinputs.h"

class startview :public QMainWindow{

    Q_OBJECT

private:

    baseChart* chart;
    userinputs* userIn;
    QWidget* userActions;
    QGroupBox* fileView;

public:
    startview();

    void deleteView();
    QLayout* createButtonsLayout();
    QLayout* createVerticalLayout();
    void createFileLayout();
    void userInput(chartTypes);
public slots:
    void createPie();
    void createLine();
    void createBar();
    void createSpline();
    void createScatter();
};


#endif // STARTVIEW_H
