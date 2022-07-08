#include "basechart.h"

baseChart::baseChart() {   

}

QString baseChart::getChartName() const{
    return chartName;
}

baseChart::~baseChart(){

}

QtCharts::QChartView* baseChart::getChartView() const {
    return chartView;
}
