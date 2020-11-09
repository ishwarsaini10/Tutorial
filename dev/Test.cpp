#include<iostream>
#include<math.h>
#include<stdio.h>
#include<iomanip>

int main(){
/*    std::cout.precision(17) ;*/
    float   x   = 1.1234    ;
    double  y   = 1.1234    ;
    std::cout<<std::setprecision(17)<<x<<std::endl ;
    std::cout<<std::setprecision(17)<<y<<std::endl ;
    double   x1  = 1.001;
    std::cout <<  "x1 = 1.001\t"  <<  std::setprecision(16)  <<  x1-1.001 <<  "\t"  <<  x1*x1  <<  std::endl;
    for(int i=1;  i<=10000;  i++){
        float x2  = x1*x1;
        std::cout <<  std::setprecision(16) << x2  <<  std::endl;
    }
    return(0)               ;
}
