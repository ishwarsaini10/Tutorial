
/*
Name  - Ishwar Singh
Aim   - To calculate relative round off error in single calculation.
Email - ishwarsaini10@gmail.com
Date  - 06.11.2020
*/

/*C++ Directives*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<fstream>
#include<stdlib.h> 

int main(){
    float  eps      = 2.22045e-16     ; // Machine Epsilon
    float  a_f      = 0.1234567890           ;
    double  a_d     = 0.1234567898           ;
    float  b_f      =  0.0987654321            ;
    double  b_d     =  0.0987654321            ;
    std::cout <<  std::fixed        ;
    std::cout <<  std::setprecision(7) <<  a_f <<  "\t"  <<  b_f <<  std::endl;
//    std::cout <<  std::setprecision(7) <<  (a/b) <<  std::endl;
    std::cout <<  std::setprecision(16)<<  "Error in a = " <<  a_d-a_f  <<  std::endl;
    std::cout <<  a_f <<  std::endl;
    
   return 0;
}


