#ifndef CHART_H
#define CHART_H

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts>
#include <QDateTime>
#include <QtCore/QTimer>

QT_CHARTS_BEGIN_NAMESPACE
class QSplineSeries;
class QValueAxis;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

/*!
*   \file 
*   \brief The file contains the chart class.
*/

/**
    @brief Chart class
*/
class Chart : public QChart
{
    Q_OBJECT
public:
    Chart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});

public slots:
    void addPoint(int x, int y, int z);

private:

    QSplineSeries *x_series;
    QSplineSeries *y_series;
    QSplineSeries *z_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_x;
    qreal m_y;

    uint pointCount;
};

#endif





