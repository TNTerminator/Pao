#include "piechart.h"

piechart::piechart():baseChart(), model(new piemodel()){
    chartView=new QtCharts::QChartView(this);
    addSeries(model->getPieSeries());
    setAnimationOptions(QChart::AllAnimations);
    chartView->setRenderHint(QPainter::Antialiasing);
    setTheme(QChart::ChartThemeBlueNcs);
}

bool piechart::ImportFromFile(const QString& FileName){
    //Clear();
    if(!model->ImportFromFile(FileName)){ //filename?
        Draw(); //errore, non riconosce draw o clear
        return false;
    }
    else{
        savedFileName=FileName;
        Draw();
        return true;
    }
}

bool piechart::SaveFile(const QString &FileName){
    return model->SaveFile(FileName);
}


void piechart::Clear(){
    removeAllSeries();
    model=new piemodel();
}
void piechart::Draw(){
    addSeries(model->getPieSeries());
}

void piechart::AddtoChart(const QStringList& SList){ //cos'è sl?
    if(!SList.first().isEmpty() && !SList.last().isEmpty()){
        model->AddtoChart(SList);
    }
}

bool piechart::RemovefromChart(const QStringList& SL){
    if(!SL.first().isEmpty()){
        if(!model->RemovefromChart(SL)) return false;
        else return true;
    }
}


