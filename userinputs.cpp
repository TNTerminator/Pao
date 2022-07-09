#include "userinputs.h"

#include "piechart.h"
#include "barchart.h"
#include "linechart.h"
#include "scatterchart.h"
#include "splinechart.h"

userinputs::userinputs(chartTypes type, QWidget* parent): firstData(nullptr), secondData(nullptr), thirdData(nullptr), tipo(type){
    setTitle("Data");

    firstData = new QLineEdit(parent);
    secondData = new QLineEdit(parent);

    QPushButton* insertValue = new QPushButton(parent);
    QPushButton* deleteValue = new QPushButton(parent);

    QWidget* dataH = new QWidget(this);
    QHBoxLayout* dataInsert = new QHBoxLayout(dataH);

    dataInsert->addWidget(firstData);
    dataInsert->addWidget(secondData);
    dataInsert->setSpacing(25);
    dataInsert->setAlignment(Qt::AlignTop);

    QVBoxLayout* dataV = new QVBoxLayout(this);

    switch(type){
        case pie:
            //setTitle("Pie Chart");
            firstData->setPlaceholderText("name");
            firstData->setAlignment(Qt::AlignLeft);

            secondData->setPlaceholderText("value");
            secondData->setValidator(new QDoubleValidator(0.0, 999.0, 2, secondData));
            secondData->setAlignment(Qt::AlignLeft);

            insertValue->setText("Add Data");
            deleteValue->setText("Remove Data");
        break;
        case line:
            //setTitle("Line Chart");
            firstData->setPlaceholderText("x");
            firstData->setValidator(new QDoubleValidator(-999.0, 999.0, 2, firstData));
            firstData->setAlignment(Qt::AlignLeft);

            secondData->setPlaceholderText("y");
            secondData->setValidator(new QDoubleValidator(-999.0, 999.0, 2, secondData));
            secondData->setAlignment(Qt::AlignLeft);

            insertValue->setText("Add point");
            deleteValue->setText("Remove point");
        break;
        case bar:
            //settitle("Bar chart");
            firstData->setPlaceholderText("category");
            firstData->setAlignment(Qt::AlignLeft);

            secondData->setPlaceholderText("Bar set");
            secondData->setAlignment(Qt::AlignLeft);

            thirdData = new QLineEdit(parent);
            thirdData->setPlaceholderText("value");
            thirdData->setValidator(new QDoubleValidator(0.0, 999.0, 2, secondData));
            thirdData->setAlignment(Qt::AlignLeft);

            dataInsert->addWidget(thirdData);

            insertValue->setText("Add Bar");
            deleteValue->setText("Remove Bar");

        break;
        case spline:
            firstData->setPlaceholderText("x");
            firstData->setValidator(new QDoubleValidator(-999.0, 999.0, 2, firstData));
            firstData->setAlignment(Qt::AlignLeft);

            secondData->setPlaceholderText("y");
            secondData->setValidator(new QDoubleValidator(999.0, 999.0, 2, secondData));
            secondData->setAlignment(Qt::AlignLeft);

            insertValue->setText("Add point");
            deleteValue->setText("Remove point");
        break;
        case scatter:
            firstData->setPlaceholderText("x");
            firstData->setValidator(new QDoubleValidator(-999.0, 999.0, 2, firstData));
            firstData->setAlignment(Qt::AlignLeft);

            secondData->setPlaceholderText("y");
            secondData->setValidator(new QDoubleValidator(999.0, 999.0, 2, secondData));
            secondData->setAlignment(Qt::AlignLeft);

            insertValue->setText("Add point");
            deleteValue->setText("Remove point");
        break;

    }

    connect(insertValue,SIGNAL(clicked(bool)),this,SIGNAL(insertData()));
    connect(deleteValue,SIGNAL(clicked(bool)),this,SIGNAL(removeData()));

    dataV->addWidget(dataH);
    dataV->addWidget(insertValue);
    dataV->addWidget(deleteValue);
    dataV->setSpacing(20);

}

QStringList userinputs::getData() const{

    QStringList data;
    data.append(firstData->text());
    data.append(secondData->text());
    if(thirdData)
        data.append(thirdData->text());

    return data;

}

chartTypes userinputs::getTipo() const{
    return tipo;
}

