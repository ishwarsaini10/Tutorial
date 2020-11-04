#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>

int main(){
    float a = 1.0     ;
    float b = 100000  ;
    float c = 1       ;

    std::cout <<  std::setprecision(7);

    float d   = sqrt(pow(b,2)-4.0*a*c);
    float x1  = (-b+d)/(2*a);
    float x2  = (-2*c)/(b+d);

    std::cout <<  std::setprecision(7)  <<   "x1=" <<  x1  <<  std::endl;
    std::cout <<  std::setprecision(7)  <<  "x2=" <<  x2  <<  std::endl;

    return(0);
}
