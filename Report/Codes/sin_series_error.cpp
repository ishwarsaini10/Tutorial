/*
 * Name - Ishwar Singh
 * Aim  - To calculate the errors in sin sum series for different values of x.
 * Email  - isingh@fnal.gov
 * Date - 07.11.2020
 */

//  C++ Directives

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cfloat>
#include<iomanip>
#include<fstream>

/*  Function to find sum of sin series for a given and number of terms to be added  */
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

/*  Main function starts here */
/*****************************************************************************************
 * The main function creates multiple files for different x-values and call the sin_series
 * function to save the value in the file.
 *****************************************************************************************
 */
int main(){
    std::ofstream my_file                   ; /*  Output file stream */
    std::string ini = "sin_series_file_v2_" ; 
    std::string txt = ".txt"                ;
    int i=1                                 ;
    for(int i=1;  i<=100;  i+=5){
        std::string final_name  = ini + std::to_string(i) + txt;
        std::ofstream my_file1              ;
        my_file1.open(final_name)           ;
        float x = i                         ;
        std::cout <<  std::fixed            ;
        std::cout <<  std::setprecision(7)  <<  x <<  std::endl ;
        for (int i=1; i<=100;  i++){
            my_file <<  std::setprecision(7)  <<  i <<  "\t"  <<  abs(sin_series(i,x)-sin_series(2*i,x)) <<  std::endl;
            my_file1 <<  std::setprecision(7)  <<  i <<  "\t"  <<  abs(sin_series(i,x)-sin_series(2*i,x)) <<  std::endl;
        }
    }
    return(0);
}
