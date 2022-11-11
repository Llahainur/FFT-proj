#include "converter.h"

Converter::Converter()
{
}



int Converter::findLen(int l){
    int len=1;
    while (len*2<l){
        len*=2;
    }
    return len;
}

void Converter::ToDouble(QList<QPointF> points, double *double_var){
    //l=findLen(points.count());
    int l=this->frameLen;

    for (int i=0;i<l;i++){
        double_var[i]=points.at(i).y();
    }
};

void Converter::PerFunc(double *x,double *y){
    //*x-=l/2;
    int f = *x;//функция градуировки
    *x=0.30431*f;
}

void Converter::ToMSeries(double *res, QList<QPointF> *points){
    points->clear();
    double x;
    double y;
    for(int i=0;i<frameLen/2;i++){
        x=double(i);
        y=res[i];
        PerFunc(&x,&y);
        points->append(QPointF(x,y));//Проверить правильность конвертирвания
    }
};

void Converter::FFTAnalysis(double *AVal, double *FTvl, int Nvl, int Nft){

    int i, j, n, m, Mmax, Istp;
    double Tmpr, Tmpi, Wtmp, Theta;
    double Wpr, Wpi, Wr, Wi;
    double *Tmvl;

    n = Nvl * 2; Tmvl = new double[n];

    for (i = 0; i < n; i+=2) {
     Tmvl[i] = 0;
     Tmvl[i+1] = AVal[i/2];
    }

    i = 1; j = 1;
    while (i < n) {
      if (j > i) {
        Tmpr = Tmvl[i]; Tmvl[i] = Tmvl[j]; Tmvl[j] = Tmpr;
        Tmpr = Tmvl[i+1]; Tmvl[i+1] = Tmvl[j+1]; Tmvl[j+1] = Tmpr;
      }
      i = i + 2; m = Nvl;
      while ((m >= 2) && (j > m)) {
        j = j - m; m = m >> 1;
      }
      j = j + m;
    }

    Mmax = 2;
    while (n > Mmax) {
      Theta = -TwoPi / Mmax; Wpi = sin(Theta);
      Wtmp = sin(Theta / 2); Wpr = Wtmp * Wtmp * 2;
      Istp = Mmax * 2; Wr = 1; Wi = 0; m = 1;

      while (m < Mmax) {
        i = m; m = m + 2; Tmpr = Wr; Tmpi = Wi;
        Wr = Wr - Tmpr * Wpr - Tmpi * Wpi;
        Wi = Wi + Tmpr * Wpi - Tmpi * Wpr;

        while (i < n) {
          j = i + Mmax;
          Tmpr = Wr * Tmvl[j] - Wi * Tmvl[j-1];
          Tmpi = Wi * Tmvl[j] + Wr * Tmvl[j-1];

          Tmvl[j] = Tmvl[i] - Tmpr; Tmvl[j-1] = Tmvl[i-1] - Tmpi;
          Tmvl[i] = Tmvl[i] + Tmpr; Tmvl[i-1] = Tmvl[i-1] + Tmpi;
          i = i + Istp;
        }
      }

      Mmax = Istp;
    }

    for (i = 0; i < Nft; i++) {
      j = i * 2; FTvl[i] = 2*sqrt(pow(Tmvl[j],2) + pow(Tmvl[j+1],2))/Nvl;
    }

    delete []Tmvl;
  }


bool Converter::AddToStack(double *x, stack<double> *st){
    st->push(*x);
    if(st->size()<frameLen){
        return 0;
    }
    else{
        return 1;
    }

};

