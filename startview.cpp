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

    /**QHBoxLayout* buttonsLayout = new QHBoxLayout;

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
    pie_button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    //connect(pie_button, &QPushButton::released, this, &MainWindow::handleButton);

    QPushButton *line_button = new QPushButton("&Line", this);
    line_button->setGeometry(150, 700, 150, 50);
    line_button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

    QPushButton *bar_button = new QPushButton("&Bar", this);
    bar_button->setGeometry(300, 700, 150, 50);
    bar_button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

    QPushButton *spline_button = new QPushButton("&Spline", this);
    spline_button->setGeometry(450, 700, 150, 50);
    spline_button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);

    QPushButton *scatter_button = new QPushButton("&Scatter", this);
    scatter_button->setGeometry(600, 700, 150, 50);
    scatter_button->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
//da provare un adjust to page, i punti così stanno fissi
    return buttonsLayout;
**/


    QDockWidget* dock=new QDockWidget(this);
    dock->setTitleBarWidget(new QWidget());
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    dock->setFixedSize(1024,250);

    QWidget* DockWidget = new QWidget(dock);

    QHBoxLayout* buttonsLayout = new QHBoxLayout(DockWidget);

    QPushButton *pie_button = new QPushButton("&Pie", DockWidget);
    connect(pie_button,SIGNAL(clicked(bool)),this,SLOT(ChangeChart(int)));

    QPushButton *line_button = new QPushButton("&Line", DockWidget);
    connect(line_button,SIGNAL(clicked(bool)),this,SLOT(ChangeChart(int)));

    QPushButton *bar_button = new QPushButton("&Bar", DockWidget);
    connect(bar_button,SIGNAL(clicked(bool)),this,SLOT(ChangeChart(int)));

    QPushButton *spline_button = new QPushButton("&Spline", DockWidget);
    connect(spline_button,SIGNAL(clicked(bool)),this,SLOT(ChangeChart(int)));

    QPushButton *scatter_button = new QPushButton("&Scatter", DockWidget);
    connect(scatter_button,SIGNAL(clicked(bool)),this,SLOT(ChangeChart(int)));


    buttonsLayout->addWidget(pie_button);
    buttonsLayout->addWidget(line_button);
    buttonsLayout->addWidget(bar_button);
    buttonsLayout->addWidget(spline_button);
    buttonsLayout->addWidget(scatter_button);

    dock->setWidget(DockWidget);
    dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    return buttonsLayout;

}

void startview::ChangeChart(int x){
    switch (x){

    case pie:{
        QLabel *label1 = new QLabel(this);
        label1->setText("1\n");
        setCentralWidget(label1);
        break;}
    case line:{
        QLabel *label2 = new QLabel(this);
        label2->setText("2\n");
        setCentralWidget(label2);
        break;}
    case bar:{
        QLabel *label3 = new QLabel(this);
        label3->setText("3\n");
        setCentralWidget(label3);
        break;}
    case spline:{
        QLabel *label4 = new QLabel(this);
        label4->setText("4\n");
        setCentralWidget(label4);
        break;}
    case scatter:{
        QLabel *label5 = new QLabel(this);
        label5->setText("5\n");
        setCentralWidget(label5);
        break;}

    }

}

