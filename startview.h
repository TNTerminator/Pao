#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QVBoxLayout>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>

class startview :public QMainWindow{
public:
    startview();

    QLayout* createButtonsLayout();
};

#endif // STARTVIEW_H
