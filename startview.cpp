#include "startview.h"

startview::startview() {

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    mainLayout->addLayout(createButtonsLayout());

    setLayout(mainLayout);
    resize(QSize(1024,768));

}

QLayout* startview::createButtonsLayout(){

    QHBoxLayout* buttonsLayout = new QHBoxLayout;

    buttonsLayout->setMargin(10);
    buttonsLayout->setSpacing(50);
    buttonsLayout->setContentsMargins(30,50,12,50);
    buttonsLayout->setAlignment(Qt::AlignCenter);

    QPushButton* newProject = new QPushButton("Nuovo Progetto",this);
    QPushButton* openProject = new QPushButton("Apri Progetto",this);

    newProject->setFixedSize(200,75);
    openProject->setFixedSize(200,75);

    buttonsLayout->addWidget(newProject);
    buttonsLayout->addWidget(openProject);

    return buttonsLayout;

}
