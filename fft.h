#ifndef FFT_H
#define FFT_H


class FFT
{
    const double TwoPi = 6.283185307179586;
    int check(double *AVal, double *FTvl, int Nvl, int Nft);
public:
    FFT();
    void FFTAnalysis(double *AVal, double *FTvl, int Nvl, int Nft);
};

#endif // FFT_H спектр для случайных сигналов
