#include "startview.h"

startview::startview() {

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    mainLayout->addLayout(createVerticalLayout());
    mainLayout->addLayout(createButtonsLayout());

    setLayout(mainLayout);
    resize(QSize(1024,1024));

}

void startview::deleteView(){
    /**if(chart != nullptr){
        delete chart;
        chart = nullptr;
    }
    if(userIn != nullptr){
        delete userIn;
        userIn = nullptr;
    }
    if(userActions != nullptr){
        delete userActions;
        userActions = nullptr;
    }
    if(fileInteraction != nullptr){
     * delete fileInteraction;
     * fileInteraction = nullptr;
    }**/
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
    dock->setFixedSize(1024,256);

    QWidget* DockWidget = new QWidget(dock);

    QHBoxLayout* buttonsLayout = new QHBoxLayout(DockWidget);

    QPushButton *pie_button = new QPushButton("&Pie", DockWidget);  
    connect(pie_button,SIGNAL(clicked(bool)),this,SLOT(createPie()));

    QPushButton *line_button = new QPushButton("&Line", DockWidget);
    connect(line_button,SIGNAL(clicked(bool)),this,SLOT(createLine()));

    QPushButton *bar_button = new QPushButton("&Bar", DockWidget);
    connect(bar_button,SIGNAL(clicked(bool)),this,SLOT(createBar()));

    QPushButton *spline_button = new QPushButton("&Spline", DockWidget);
    connect(spline_button,SIGNAL(clicked(bool)),this,SLOT(createSpline()));

    QPushButton *scatter_button = new QPushButton("&Scatter", DockWidget);
    connect(scatter_button,SIGNAL(clicked(bool)),this,SLOT(createScatter()));


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

QLayout* startview::createVerticalLayout(){

    QDockWidget* dockV=new QDockWidget(this);
    dockV->setTitleBarWidget(new QWidget());
    dockV->setAllowedAreas(Qt::LeftDockWidgetArea);
    dockV->setFixedSize(512,768);

    QWidget* DockWidgetV = new QWidget(dockV);
    QVBoxLayout* layout=new QVBoxLayout(DockWidgetV);

    userActions=new QWidget(DockWidgetV);
    QVBoxLayout* VLayout=new QVBoxLayout(userActions);
    userActions->setLayout(VLayout);
    //VLayout->setAlignment(Qt::AlignTop);

    layout->addWidget(userActions);

    dockV->setWidget(DockWidgetV);
    dockV->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea,dockV);

    return(layout);

}

void startview::userInput(chartTypes type){
    userIn = new userinputs(type, userActions);
    userActions->layout()->addWidget(userIn);
}

void startview::createPie(){
    QLabel *label1 = new QLabel(this);
    label1->setText("1\n");
    setCentralWidget(label1);
    userInput(pie);

}
void startview::createLine(){

    QLabel *label2 = new QLabel(this);
    label2->setText("2\n");
    setCentralWidget(label2);

}
void startview::createBar(){

    QLabel *label3 = new QLabel(this);
    label3->setText("3\n");
    setCentralWidget(label3);

}
void startview::createSpline(){

    QLabel *label4 = new QLabel(this);
    label4->setText("4\n");
    setCentralWidget(label4);

}
void startview::createScatter(){

    QLabel *label5 = new QLabel(this);
    label5->setText("5\n");
    setCentralWidget(label5);

}
