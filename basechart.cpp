#include "basechart.h"

QString baseChart::getSavedFileName() const{
    return savedFileName;
}

baseChart::~baseChart(){

}

QtCharts::QChartView* baseChart::getChartView() const {
    return chartView;
}
