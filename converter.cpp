#include "converter.h"

Converter::Converter()
{
}
void Converter::ToDouble(QList<QPointF> points, double *double_var){

    for (int i=0;i<l;i++){
        double_var[i]=points.at(i).y();
    }
};

void Converter::ToMSeries(double *double_var,QLineSeries *series_var){
    series_var->clear();
    size_t l = sizeof( double_var ) / sizeof( *double_var );
    for ( size_t i = 0; i < l; i++ )
    {
        //добавить в сериз переменную
    }
};


