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
    int l=this->l;

    for (int i=0;i<l;i++){
        double_var[i]=points.at(i).y();
    }
    //qDebug()<<l;
};

void Converter::PerFunc(double *x,double *y){
    //*x-=l/2;
    int f = *x;
    *x=0.30431*1.6*f;
}

void Converter::ToMSeries(double *res, QList<QPointF> *points){
    points->clear();
    double x;
    double y;
    for(int i=0;i<l/2;i++){
        x=double(i);
        y=res[i];
        PerFunc(&x,&y);
        points->append(QPointF(x,y));//Проверить правильность конвертирвания
    }
};


