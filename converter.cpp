#include "converter.h"

Converter::Converter()
{
}


void Converter::ToDouble(QList<QPointF> points, double *double_var){
    int l=this->frameLen;
    for (int i=0;i<l;i++){
        double_var[i]=points.at(i).y();
    }
};

void Converter::PerFunc(double *x,double *y){

    *x=grad_Kx**x;
    *y=grad_Ky**y;

    //qDebug()<<*y<<" ";//<<yf;
}

void Converter::ToMSeries(double *res, QList<QPointF> *points){
    points->clear();
    double x;
    double y;
    for(int i=0;i<frameLen/2;i++){
        x=double(i);
        y=res[i];
        //PerFunc(&x,&y);
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


void Converter::AverageForArrays(double * arr_of_vals, double * aver_res, double * fft_res){
    //добавляем каждый элемент массива в стек по i (0 - в 0, посл - в посл)
    //считаем среднее квадратичное по элем
    //передаем в fft
    int i;
    int j;
    aver_calls+=1;
    for (i=0;i<frameLen;i++){
        //aver_res[i]=sqrt(arr_of_vals[i]*arr_of_vals[i]);
//        if (i<frameLen-2){
//            aver_res[i]=(aver_res[i+1]+aver_res[i])/2;
//        }
        //aver_res[i]=sqrt((aver_res[i]*aver_res[i])+(arr_of_vals[i] * arr_of_vals[i]));
        aver_res[i]=arr_of_vals[i];
        aver_res[i]=(aver_res[i]*aver_calls+arr_of_vals[i])/aver_calls+1;

        aver_res[i]=WindowFuncBarlett(aver_res[i]);
        if (i==frameLen-1 and aver_calls==aver_calls_max){
            FFTAnalysis(aver_res,fft_res,frameLen,frameLen);
            for (j=0;j<frameLen;j++){
                aver_res[i]=0;
            }
            aver_calls=0;

        }
    }

};

double Converter::WindowFuncBarlett(double x){
    return 1-2*abs(x);
}

