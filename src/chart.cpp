#include "chart.hpp"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags) : 
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    x_series(new QSplineSeries(this)), 
    y_series(new QSplineSeries(this)),
    z_series(new QSplineSeries(this)),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_x(0), m_y(0),
    pointCount(30)
{   
    QObject::connect(&timer, &QTimer::timeout, this, &Chart::timerTimeout);
    QPen red(Qt::red);
    QPen green(Qt::green);
    QPen blue(Qt::blue);

    red.setWidth(2);
    green.setWidth(2);
    blue.setWidth(2);

    x_series->setPen(red);
    y_series->setPen(green);
    z_series->setPen(blue);

    addSeries(x_series);
    addSeries(y_series);
    addSeries(z_series);

    m_axisX->setLabelsVisible(false);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);

    x_series->attachAxis(m_axisX);
    x_series->attachAxis(m_axisY);
    y_series->attachAxis(m_axisX);
    y_series->attachAxis(m_axisY);
    z_series->attachAxis(m_axisX);
    z_series->attachAxis(m_axisY);

    m_axisX->setTickCount(this->pointCount);
    m_axisX->setRange(0, 10);
    m_axisY->setRange(-5, 10);

    timer.start(200);


    this->legend()->hide();
    this->setAnimationOptions(QChart::NoAnimation);
}

void Chart::timerTimeout() {
    int x = QRandomGenerator::global()->bounded(10) - 2.5;
    int y = QRandomGenerator::global()->bounded(10) - 2.5;
    int z = QRandomGenerator::global()->bounded(10) - 2.5;

    this->addPoint(x, y, z);
}

void Chart::addPoint(int x, int y, int z)
{
    if(this->x_series->points().size() > this->pointCount) this->x_series->remove(0);
    if(this->y_series->points().size() > this->pointCount) this->y_series->remove(0);
    if(this->z_series->points().size() > this->pointCount) this->z_series->remove(0);
    
    m_x += (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    this->x_series->append(m_x + 10, x);
    this->y_series->append(m_x + 10, y);
    this->z_series->append(m_x + 10, z);

    scroll(plotArea().width() / m_axisX->tickCount(), 0);
}