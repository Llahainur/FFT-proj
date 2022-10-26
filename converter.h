#ifndef CONVERTER_H
#define CONVERTER_H
#include <QLineSeries>

class Converter//преобразует m_series в массив чисел и обратно
{
    int findLen(int l);

public:
    Converter();
    void ToDouble(QList<QPointF> points,double *);
    void ToMSeries(double *,QList<QPointF> points);
    int l= 4096;
    //int l=2048;
};

#endif // CONVERTER_H
