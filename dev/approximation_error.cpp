

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cfloat>
#include<iomanip>
#include<fstream>

float sin_series(int N, float x){
    float s   ;
    float t   ;
    s = t = x ;
    for(int i=1;  i<N;  i++){
        t*=-x*x/((2*i+1)*2*i);
        s+=t;
    } 
    return s;
}


int main(){
    std::ofstream my_file ;
    my_file.open("aprroximation.txt");
    std::cout <<  std::fixed  ;
//    std::cout <<  std::setprecision(7)  <<  x <<  std::endl ;
    float x = 10.0 ;
    std::cout <<  sin(x)  <<  std::endl;
//    float x_degree  = 180./M_PI ;
    for (int i=1; i<=100;  i++){
        my_file <<  std::fixed  <<  std::setprecision(7)  <<  i   <<  "\t"  <<  sin_series(i,x) <<  "\t"<<  sin(x)  <<  "\t"  <<  abs((abs(sin_series(i,x))-abs(sin(x)))) <<  std::endl;
    }

return(0);
}
