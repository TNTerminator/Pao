#ifndef BASECHART_H
#define BASECHART_H

#include <QtCharts>

class baseChart : public QtCharts::QChart{
private:
    QString chartName;
    QtCharts::QChartView* chartView;
public:
    QtCharts::QChartView* getChartView() const;
    QString getChartName() const;
    virtual ~baseChart();
    baseChart();
};

#endif // BASECHART_H
