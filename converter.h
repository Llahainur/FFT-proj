#ifndef CONVERTER_H
#define CONVERTER_H
#include <QLineSeries>
#include <stack>

#include <math.h>

using namespace std;

#define _USE_MATH_DEFINES

class Converter//преобразует m_series в массив чисел и обратно
{
    const double TwoPi = 2*M_PI;
    const double PI = M_PI;
    const double grad_Kx=1;
    const double grad_Ky=1;
    int aver_calls=0;
    const int aver_calls_max=50;

public:
    Converter();
    void ToDouble(QList<QPointF> points,double *);
    void ToMSeries(double *,QList<QPointF> *);
    void PerFunc(double *x, double *y);
    void AverageForArrays(double * arr_of_vals, double * aver_res, double * fft_res);
    void FFTAnalysis(double *AVal, double *FTvl, int Nvl, int Nft);
    double WindowFuncBarlett(double x);//Треугольное
    const int frameLen=8192;
};

#endif // CONVERTER_H
