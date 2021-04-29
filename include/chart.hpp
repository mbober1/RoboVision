#ifndef CHART_H
#define CHART_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

class myChart : public QChart
{
    Q_OBJECT
public:
    explicit myChart(QObject *parent = 0);
    QLineSeries *series = new QLineSeries();

signals:
public slots:
private:
};

#endif





