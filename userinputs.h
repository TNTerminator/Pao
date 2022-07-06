#ifndef USERINPUTS_H
#define USERINPUTS_H

#include <QObject>
#include <QDockWidget>
#include <QTableView>

enum chartTypes{pie, line, bar, spline, scatter};
class userinputs : public QTableView{

    Q_OBJECT

public:
    userinputs(chartTypes, QWidget* p =nullptr);
};

#endif // USERINPUTS_H
