#ifndef CONVERTER_H
#define CONVERTER_H
#include <QLineSeries>
#include <stack>

#include <math.h>

using namespace std;

#define _USE_MATH_DEFINES

class Converter//преобразует m_series в массив чисел и обратно
{
    int findLen(int l);
    const double TwoPi = 2*M_PI;
    const double PI = M_PI;

public:
    Converter();
    void ToDouble(QList<QPointF> points,double *);
    void ToMSeries(double *,QList<QPointF> *);
    void PerFunc(double *x, double *y);
    bool AddToStack(double *x, stack<double> *st);
    void FFTAnalysis(double *AVal, double *FTvl, int Nvl, int Nft);
    const int frameLen=4096;
};

#endif // CONVERTER_H
