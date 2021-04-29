#include "chart.hpp"
#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

Chart::Chart(QGraphicsItem *parent, Qt::WindowFlags wFlags) : 
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    x_series(0), y_series(0), z_series(0),
    m_axisX(new QValueAxis()),
    m_axisY(new QValueAxis()),
    m_step(0),
    m_x(5),
    m_y(1)
{   
    QObject::connect(&m_timer, &QTimer::timeout, this, &Chart::handleTimeout);
    m_timer.setInterval(300);

    x_series = new QSplineSeries(this);
    y_series = new QSplineSeries(this);
    z_series = new QSplineSeries(this);

    QPen red(Qt::red);
    QPen green(Qt::green);
    QPen blue(Qt::blue);

    red.setWidth(3);
    green.setWidth(3);
    blue.setWidth(3);

    x_series->setPen(red);
    y_series->setPen(green);
    z_series->setPen(blue);

    x_series->append(m_x, m_y);
    y_series->append(m_x, m_y);
    z_series->append(m_x, m_y);

    addSeries(x_series);
    addSeries(y_series);
    addSeries(z_series);

    addAxis(m_axisX,Qt::AlignBottom);
    addAxis(m_axisY,Qt::AlignLeft);

    x_series->attachAxis(m_axisX);
    x_series->attachAxis(m_axisY);
    y_series->attachAxis(m_axisX);
    y_series->attachAxis(m_axisY);
    z_series->attachAxis(m_axisX);
    z_series->attachAxis(m_axisY);

    m_axisX->setTickCount(50);
    m_axisX->setRange(0, 10);
    m_axisY->setRange(-5, 10);

    m_timer.start();


    this->setTitle("Dynamic spline chart");
    this->legend()->hide();
    // this->setAnimationOptions(QChart::AllAnimations);

    // QDateTime timestamp;
    // timestamp.setDate(QDate::currentDate());
    // timestamp.setTime(QTime::currentTime());
    // this->X->append(timestamp.currentSecsSinceEpoch(), 0);
    // this->X->append(0, 6);
    // this->X->append(2, 4);
    // this->X->append(3, 8);
    // this->X->append(7, 4);
    // this->X->append(10, 5);
    // // *X << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    // this->legend()->hide();
    // this->addSeries(X);
    // this->createDefaultAxes();
    // this->setAxisY()
    // this->setTitle("Simple line chart example");

    // axisX->setRange(timestamp.currentSecsSinceEpoch(), timestamp.currentSecsSinceEpoch() + 10);
    // axisX->setTickCount(10);
    // axisX->setLabelFormat("%.2f");

    // timer.start(1000);
    // connect(&timer, &QTimer::timeout, this, &Chart::addPoint);
    // this->setAxisX(axisX, X);
    // X->attachAxis(axisY);
}
void Chart::addPoint() {
    QDateTime timestamp;
    timestamp.setDate(QDate::currentDate());
    timestamp.setTime(QTime::currentTime());
    this->X->append(timestamp.currentSecsSinceEpoch(), rand() % 8 + 1);
    if(this->X->points().size() > 10) this->X->remove(0);
    qDebug() << timestamp.currentSecsSinceEpoch() << timestamp << this->X->points().size();
}

void Chart::handleTimeout()
{
    qreal x = plotArea().width() / m_axisX->tickCount();
    qreal y = (m_axisX->max() - m_axisX->min()) / m_axisX->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) - 2.5;
    x_series->append(m_x, m_y);
    y_series->append(m_x, m_y + 1);
    z_series->append(m_x, m_y - 1);
    scroll(x, 0);
}