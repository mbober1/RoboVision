#include "chart.hpp"

myChart::myChart(QObject *parent)
{
    this->series->append(0, 6);
    this->series->append(2, 4);
    this->series->append(3, 8);
    this->series->append(7, 4);
    this->series->append(10, 5);
    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    this->legend()->hide();
    this->addSeries(series);
    this->createDefaultAxes();
    this->setTitle("Simple line chart example");
}