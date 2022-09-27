#include <QtTest>
#include "../fft.h"
#include "../fft.cpp"
#include "math.h"
// add necessary includes here
#define M_PI 3.14159265358979323846

double funk(int x){
    return sin(x);
}

class test : public QObject
{
    Q_OBJECT

public:
    test();
    ~test();

private slots:
    void test_case1();

};

test::test()
{
    const double PI=M_PI;
    FFT f;
    double AVal[8];
    double FTvl[8];
    int l=8;
    for(int i=0;i<l;i++){
        AVal[i]=funk(i/2);
    }
    //double *AVal, double *FTvl, int Nvl, int Nft
    // AVal - массив анализируемых данных, Nvl - длина массива должна быть кратна степени 2.
    // FTvl - массив полученных значений, Nft - длина массива должна быть равна Nvl.
    f.FFTAnalysis(AVal,FTvl,l,l);
    for(int i=0;i<l;i++){
        qDebug()<<FTvl[i];
    }

}

test::~test()
{

}

void test::test_case1()
{

}

QTEST_APPLESS_MAIN(test)

#include "tst_test.moc"

