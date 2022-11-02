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

void Converter::ToMSeries(double *res, QList<QPointF> *points){
    points->clear();
    for(int i=0;i<l;i++){
         points->append(QPointF(int(i-l/2),res[i]));
    }
};


