

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cfloat>
#include<iomanip>
#include<fstream>

float iterative_addition(float x, float dx, float true_val, int n){
    float temp  = x ;
    for (int i=1;i<=n;i++){
        x+=dx;
    }
    //return abs(true_val-x);
    return abs((true_val-x)/true_val);
    //std::cout <<  temp  <<  "\t"  <<  dx  <<  "\t" << x <<  "\t"  << abs(true_val-x) <<     std::endl;
}

int main(){
    float x1  = 10E-1 ;
    float dx1 = 10E-1 ;
    float true_val  = 0.1 ;
    std::ofstream my_file ;
    my_file.open("iterative_addition_v2.txt");
    
    for(int j = 1;  j<=10E6;  j*=10){ 
        true_val  = x1*pow(10,j)  ;
        my_file <<  j <<  "\t"  << iterative_addition(x1,dx1,  true_val, j) <<  std::endl; 
    }

    return 0;
}

