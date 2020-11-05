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

float sum_up (float N){
    float  t = 1.0 ;
    float  s = 1.0 ;

    for(float i=1;  i<N;  i++){
        t*=i/(i+1)  ;
        s+=t        ;
    }
    return(s)       ;
}


float sum_down (float N){
    float  t = 1/N ;
    float  s = 1/N ;

    for(float i=N-1;  i>0;  i--){
        t*=(i+1)/i  ;
        s+=t        ;
    }
    return(s)       ;
}

int main(){
    float sum_up   (float)   ;
    float sum_down (float)   ;
    std::ofstream my_file   ;
    my_file.open("Sum_up_and_down_05_11_2020.txt");

    for( int i=1;  i<=100000;  i++){
       // my_file <<  std::setprecision(14) <<  log10(i) <<  "\t"  <<  sum_up(i) <<  "\t"  <<  sum_down(i) <<  "\t"  <<  log10(abs((sum_up(i)-sum_down(i))/(abs(sum_up(i))+abs(sum_down(i)))))  <<  std::endl;
        my_file <<  std::scientific <<  std::setprecision(14) <<  i <<  "\t"  <<  sum_up(i) <<  "\t"  <<  sum_down(i) <<  "\t"  <<  (sum_up(i)-sum_down(i))/(abs(sum_up(i))+abs(sum_down(i)))  <<  std::endl;


//        std::cout<<  std::setprecision(14) << log10(i) <<  "\t"  <<  sum_up(i) <<  "\t"  <<  sum_down(i) <<  std::endl;
    }
    return 0;
}
