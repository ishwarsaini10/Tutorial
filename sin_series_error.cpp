
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
    std::string ini = "sin_series_file_v2_";
    std::string txt = ".txt";
    int i=1;
    for(int i=1;  i<=100;  i+=5){
        std::string final_name  = ini + std::to_string(i) + txt;
        std::ofstream my_file1  ;
        my_file1.open(final_name);
//        my_file.open("sin_series_07_11_2020.txt") ;
        float x = i ;
        std::cout <<  std::fixed  ;
        std::cout <<  std::setprecision(7)  <<  x <<  std::endl ;
        for (int i=1; i<=100;  i++){
            my_file <<  std::setprecision(7)  <<  i <<  "\t"  <<  abs(sin_series(i,x)-sin_series(2*i,x)) <<  std::endl;
            my_file1 <<  std::setprecision(7)  <<  i <<  "\t"  <<  abs(sin_series(i,x)-sin_series(2*i,x)) <<  std::endl;
        }
    }
    return(0);
}
