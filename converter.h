#ifndef CONVERTER_H
#define CONVERTER_H
#include <QLineSeries>

class Converter//преобразует m_series в массив чисел и обратно
{
public:
    Converter();
    double * ToDouble(QLineSeries *);
    QLineSeries * ToMSeries(double *);
};

#endif // CONVERTER_H
