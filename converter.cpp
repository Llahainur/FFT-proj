#include "converter.h"

Converter::Converter()
{

}
void Converter::ToDouble(QLineSeries *series_var, double *double_var){
    auto points = series_var->points();
    int l=points.length();
    for (int i=0;i<l;i++){
        double_var[i]=series_var->at(i).y();
    }
};

void Converter::ToMSeries(double *double_var,QLineSeries *series_var){

};


