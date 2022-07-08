#ifndef PIEMODEL_H
#define PIEMODEL_H

#include "basechart.h"
class piemodel{
private:
    QPieSeries* PieSeries;
public:
    piemodel();
    QPieSeries* getPieSeries() const;
    bool ImportFromFile(const QString&);
    bool SaveFile(const QString &);
    void AddtoChart(const QStringList&);
    bool RemovefromChart(const QStringList&);
};

#endif // PIEMODEL_H
