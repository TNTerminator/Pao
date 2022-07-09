#include "startview.h"

startview::startview() {

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setSpacing(0);
    mainLayout->setMargin(0);

    mainLayout->addLayout(createVerticalLayout());
    mainLayout->addLayout(createButtonsLayout());

    createFileLayout();

    setLayout(mainLayout);
    resize(QSize(1024,768));

}

QLayout* startview::createButtonsLayout(){

    QDockWidget* dock=new QDockWidget(this);
    dock->setTitleBarWidget(new QWidget());
    dock->setAllowedAreas(Qt::BottomDockWidgetArea);
    dock->setFixedSize(1024,64);

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

    layout->addWidget(userActions);

    dockV->setWidget(DockWidgetV);
    dockV->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea,dockV);

    return layout;

}

void startview::createFileLayout(){

    fileView=new QGroupBox("File Action",userActions);

    QPushButton* FileOpenButton=new QPushButton("Save",userActions);
    //connect(FileOpenButton,SIGNAL(clicked(bool)),this,SLOT(OpenFileDialogue()));

    QPushButton* FileSaveNewButton=new QPushButton("Open",userActions);
    //connect(FileSaveNewButton,SIGNAL(clicked(bool)),this,SLOT(SaveFileDialogue()));

    QPushButton* FileSavetoCurrentButton=new QPushButton(tr("Save as"),userActions);
    //connect(FileSavetoCurrentButton,SIGNAL(clicked(bool)),this,SLOT(SavetoCurrent()));


    QHBoxLayout* FileH=new QHBoxLayout(fileView);
    FileH->addWidget(FileOpenButton);
    FileH->addWidget(FileSaveNewButton);
    FileH->addWidget(FileSavetoCurrentButton);

    userActions->layout()->addWidget(fileView);

}

void startview::userInput(chartTypes type){

    userIn = new userinputs(type, userActions);
    userActions->layout()->addWidget(userIn);

    connect(userIn,SIGNAL(insertData()),this,SLOT(addData()));
    connect(userIn,SIGNAL(removeData()),this,SLOT(deleteData()));
}

void startview::createPie(){

    userActions->layout()->removeWidget(userIn);
    chart = new piechart();
    setCentralWidget(chart->getChartView());
    userInput(pie);

}
void startview::createLine(){

    userActions->layout()->removeWidget(userIn);
    chart = new linechart();
    setCentralWidget(chart->getChartView());
    userInput(line);

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

void startview::addData(){
    if(userIn->getTipo()==pie){
        if(!chart->RemovefromChart(userIn->getData())){chart->AddtoChart(userIn->getData());}
        else {chart->AddtoChart(userIn->getData());}
    }
    else{chart->AddtoChart(userIn->getData());}
}

void startview::deleteData(){
    if(!chart->RemovefromChart(userIn->getData())){QMessageBox::warning(this,"Error","No match found",QMessageBox::Ok);}
}
