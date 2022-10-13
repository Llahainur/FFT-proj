#ifndef CONVERTER_H
#define CONVERTER_H
#include <QLineSeries>

class Converter//преобразует m_series в массив чисел и обратно
{

public:
    Converter();
    void ToDouble(QList<QPointF> points,double *);
    void ToMSeries(double *,QLineSeries *);
    const int l= 4096;
};

#endif // CONVERTER_H
