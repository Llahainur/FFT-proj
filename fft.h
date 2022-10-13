#ifndef FFT_H
#define FFT_H
#include <math.h>
#define _USE_MATH_DEFINES

class FFT
{
    const double TwoPi = 2*M_PI;
    int check(double *AVal, double *FTvl, int Nvl, int Nft);
public:
    FFT();
    void FFTAnalysis(double *AVal, double *FTvl, int Nvl, int Nft);
};

#endif // FFT_H спектр для случайных сигналов
