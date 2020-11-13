
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cfloat>
#include<iomanip>
#include<fstream>

void iterative_addition(float x, float dx, float true_val){
    float temp  = x ;
    for (int i=1;i<=10E6;i++){
        x+=dx;
    }
    std::cout <<  temp  <<  "\t"  <<  dx  <<  "\t" << x <<  "\t"  << abs((true_val-x)/true_val) <<     std::endl;
}

int main(){
    float x1  = 0.1 ;
    float dx1 = 0.1 ;
    float x2  = 0.01  ;
    float dx2 = 0.01  ;
    float x3  = 0.001 ;
    float dx3 = 0.001 ;
    float x4  = 1E-7  ;
    float dx4 = 1.0E-7;  
    iterative_addition(x1,dx1,  10E5);
    iterative_addition(x2,dx2,  10E4);
    iterative_addition(x3,dx3,  10E3);
    iterative_addition(x4,dx4,  10E-1);

    return 0;
}

