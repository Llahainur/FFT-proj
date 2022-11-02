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

void Converter::ToMSeries(double *double_var, QList<QPointF> *points){
    //series_var->clear();
    points->clear();
    QPoint p;
    size_t l = sizeof( double_var ) / sizeof( *double_var );
    for ( size_t i = 0; i < l; i++ )
    {
        p = QPoint(i,double_var[i]);
        points->append(p);
    }
};


