#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cfloat>
#include<iomanip>

int main(){
    int   i;
    double t;
    double s;
    double e  = 1.0e-7;
    double pi  = M_PI  ;
    double x   = 20;
    std::cout <<  std::setprecision(10);
    i = 1;
    s = t = x;
    do{
        t*=-x*x/((2*i+1)*2*i);
        s+=t;
        i+=1;
        std::cout <<  t <<  std::endl;
    } while  (fabs(t/s)>e);
    std::cout <<  "Sin(x) from series is = "  <<  s <<  std::endl;
    std::cout <<  "Sin(x) exact = "  <<  sin(x) <<  std::endl;
    return(0);
}
