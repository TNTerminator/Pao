#ifndef BARMODEL_H
#define BARMODEL_H

#include "basechart.h" //cosa includiamo?

class barmodel{
private:
    QBarCategoryAxis* CAxis;
    QList<QBarSet*>* BSets;
    QBarSeries* BSeries;
    unsigned int FindMakeCategory(const QString& cat);
    unsigned int FindMakeBarSet(const QString& bar);
    int FindCategory(const QString & cat) const;
    int FindBarSet(const QString & bar) const;
    bool RemoveEmptyCategory(unsigned int);
    bool RemoveEmptyBarSet(unsigned int);
public:
    barmodel();
    QList<QBarSet*>* BarSets() const;
    QBarSeries* BarSeries() const;
    QBarCategoryAxis* CategoryAxis() const;
    bool ImportFromFile(const QString& FileName);
    bool SaveFile(const QString &FileName);
    void AddtoModel(const QStringList& SL);
    bool RemovefromModel(const QStringList& SL);
};

#endif // BARMODEL_H
