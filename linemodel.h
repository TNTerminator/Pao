#ifndef LINEMODEL_H
#define LINEMODEL_H

#include "piechart.h"

class linemodel{
private:
    QLineSeries* LineSeries;
public:
    linemodel();
    QLineSeries* GetLineSeries() const;
    bool ImportFromFile(const QString& FileName);
    bool SaveFile(const QString &FileName);
    void AddtoChart(const QStringList& SL);
    bool RemovefromChart(const QStringList& SL);
};

#endif // LINEMODEL_H
