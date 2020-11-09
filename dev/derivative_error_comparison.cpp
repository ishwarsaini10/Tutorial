
/*
 *  Name  - Ishwar Singh
 *  Purpose - Comparison of errors in derivative of a function (sin).
 *  Email - ishwarsaini10@gmail.com
 *
*/

/* C++ Directives */

#include<iostream>
#include<math.h>
#include<stdio.h>
#include<iomanip>
#include<cfloat>
#include<fstream>

int main(){
    float deriv               ;
    float second_deriv        ;
    float discrete_error      ;
    float arthmatic_error     ;
    float total_error         ;
    float h                   ;
    float x   = 2.0           ;
    float eps = 1.0E-7        ;
    float err                 ;
    std::ofstream  myfile;
    myfile.open("derivative_comparison.dat");
    std::cout <<  std::setprecision(7);

    for(int i=1; i<=1E7;  i+=10000){
        h = 1.0E-7*i;
        deriv = (sin(x+h) - sin(x))/h ;
        discrete_error  = cos(x)  - deriv ;
        arthmatic_error = 2*sin(x)*eps/h  ;
        myfile <<  h << "\t" << deriv <<  "\t"  <<  abs(discrete_error)+abs(arthmatic_error)  << std::endl ;
    }
    myfile.close();
    return 0;
}
