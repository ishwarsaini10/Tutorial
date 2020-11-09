/*
Name  - Ishwar Singh
Aim   - To observe the difference between the methods of series addition (up and down).
Email - ishwarsaini10@gmail.com
Date  - 05.11.2020
*/

/*C++ Directives*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<fstream>

double sum_up (double N){
    double  t = 1.0 ;
    double  s = 1.0 ;

    for(double i=1;  i<N;  i++){
        t*=i/(i+1)  ;
        s+=t        ;
    }
    return(s)       ;
}


double sum_down (double N){
    double  t = 1/N ;
    double  s = 1/N ;

    for(double i=N-1;  i>0;  i--){
        t*=(i+1)/i  ;
        s+=t        ;
    }
    return(s)       ;
}

int main(){
    double sum_up   (double)   ;
    double sum_down (double)   ;
    std::ofstream my_file   ;
    my_file.open("Sum_up_and_down_05_11_2020.txt");

    for( int i=1;  i<=1000;  i++){
        my_file <<  std::setprecision(14) <<  i  <<  "\t"  <<  abs((sum_up(i)-sum_down(i))/(abs(sum_up(i))+abs(sum_down(i))))  <<  std::endl;

       // my_file <<  std::scientific <<  std::setprecision(14) <<  i <<  "\t"  <<  sum_up(i) <<  "\t"  <<  sum_down(i) <<  "\t"  <<  (sum_up(i)-sum_down(i))/(abs(sum_up(i))+abs(sum_down(i)))  <<  std::endl;


//        std::cout<<  std::setprecision(14) << log10(i) <<  "\t"  <<  sum_up(i) <<  "\t"  <<  sum_down(i) <<  std::endl;
    }
    return 0;
}
