#ifndef CHART_H
#define CHART_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QDateTime>
#include <QtCharts/QChart>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

class Chart : public QChart
{
    Q_OBJECT
public:
    Chart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    QLineSeries *X = new QLineSeries();
    QLineSeries *Y = new QLineSeries();
    QLineSeries *Z = new QLineSeries();
    QValueAxis *axisX = new QValueAxis;

public slots:
    void addPoint();
    void handleTimeout();

private:
    QTimer timer;
    QTimer m_timer;

    QSplineSeries *x_series;
    QSplineSeries *y_series;
    QSplineSeries *z_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};

#endif





