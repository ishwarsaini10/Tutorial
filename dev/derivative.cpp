/*
 *  Name  - Ishwar Singh
 *  Purpose - Find errors in derivative of a function.
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
    myfile.open("derivative3.txt");
    std::cout <<  std::setprecision(7);
/*    for(int i=1;  i<= 1E7; i++){
        h     = (1.0E-7)*i            ;
        deriv = (sin(x+h) - sin(x))/h ;
        second_deriv  = (sin(x+2.0*h)  - 2.0*sin(x+h)  - sin(x))/pow(h,2);
        err   = abs(deriv - cos(x))   ;
//        discrete_error  = abs(-(sin(x)  * h)/2.0);
//        arthmatic_error = (2.0*sin(x)*eps)/h  ;
        discrete_error  = h/2.0;
        arthmatic_error = eps/h;
        total_error     = discrete_error  + arthmatic_error ;
//        std::cout <<  h << "\t" <<  deriv <<  "\t"  <<  cos(x)  <<  "\t"  <<  err << "\t" <<  discrete_error  <<  "\t"  <<  arthmatic_error <<  "\t"  <<  abs(total_error) << std::endl ;
         myfile <<  h << "\t" <<  deriv <<  "\t"  <<  cos(x)  <<  "\t"  <<  err << "\t" <<  discrete_error  <<  "\t"  <<  arthmatic_error <<  "\t"  <<  abs(total_error) << std::endl ;
    }*/
//    myfile.close();

/*    for(int i=1;  i<=10;  i++){
        std::cout <<  sin(i)  <<  std::endl;
    }*/

    for(int i=1; i<=1E7;  i+=1000){
        h = 1.0E-7*i;
        deriv = (sin(x+h) - sin(x))/h ;
        discrete_error  = cos(x)  - deriv ;
        arthmatic_error = 2*sin(x)*eps/h  ;
        myfile <<  h << "\t" <<  deriv <<  "\t"  <<  cos(x)  << "\t" <<  discrete_error  <<  "\t"  <<  arthmatic_error << std::endl ;
    }
    myfile.close();
    return 0;
}
