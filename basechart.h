#ifndef BASECHART_H
#define BASECHART_H

#include <QtWidgets>
#include <QtCharts>
#include <QFile>
#include <QDebug>
#include <QString>


class baseChart : public QtCharts::QChart{
protected:
    QString chartName;
    QtCharts::QChartView* chartView;
public:
    QtCharts::QChartView* getChartView() const;
    QString getChartName() const;
    virtual ~baseChart();
    virtual bool ImportFromFile(const QString&)=0;
    virtual bool SaveFile(const QString &)=0;
    virtual void AddtoChart(const QStringList&)=0;
    virtual bool RemovefromChart(const QStringList&)=0;
};

#endif // BASECHART_H
