#ifndef CONVERTER_H
#define CONVERTER_H
#include <QLineSeries>

class Converter//преобразует m_series в массив чисел и обратно
{
public:
    Converter();
    void ToDouble(QLineSeries *,double *);
    void ToMSeries(double *,QLineSeries *);
};

#endif // CONVERTER_H
