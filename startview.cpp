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

   // QPushButton* newProject = new QPushButton("Nuovo Progetto",this);
   // QPushButton* openProject = new QPushButton("Apri Progetto",this);

    //newProject->setFixedSize(200,75);
    //openProject->setFixedSize(200,75);

    //buttonsLayout->addWidget(newProject);
    //buttonsLayout->addWidget(openProject);

    QLabel *label = new QLabel(this);
    label->move( 5, 5);
    label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    label->setText("Modifica Dati (inserimento)\n");
    label->setAlignment(Qt::AlignBottom | Qt::AlignCenter);
    label->setGeometry(5, 5, 200, 50);

//per l'incapsulamento sarebbe bello fare una dimensione std e richiamare quella come il proj del mio friend
    //
    QPushButton *pie_button = new QPushButton("&Pie", this);
    pie_button->setGeometry(5, 700, 150, 50);
    connect(pie_button, &QPushButton::released, this, &MainWindow::handleButton);

    QPushButton *line_button = new QPushButton("&Line", this);
    line_button->setGeometry(150, 700, 150, 50);

    QPushButton *bar_button = new QPushButton("&Bar", this);
    bar_button->setGeometry(300, 700, 150, 50);

    QPushButton *spline_button = new QPushButton("&Spline", this);
    spline_button->setGeometry(450, 700, 150, 50);

    QPushButton *scatter_button = new QPushButton("&Scatter", this);
    scatter_button->setGeometry(600, 700, 150, 50);
//da provare un adjust to page, i punti così stanno fissi
    return buttonsLayout;

}

