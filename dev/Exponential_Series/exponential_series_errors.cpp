
/*
 * Name - Ishwar Singh
 * Aim  - To calculate the errors in exponential series for different values of x.
 * Email  - isingh@fnal.gov
 * Date - 09.11.2020
 */

//  C++ Directives

#include  <iostream>
#include  <stdio.h>
#include  <math.h>
#include  <cfloat>
#include  <iomanip>
#include  <fstream>

/*  Function to find sum of exponential series for a given and number of terms to be added  */
double exp_series(int N, double x){
    double s   ;
    double t   ;
    s = t = -x ;
    for(int i=1;  i<N;  i++){
        t*=-x/(i+1);
        s+=t;
    } 
    return 1.+s;
}

/*
 * ****************************************************************************************
 * The main function creates multiple files for different x-values and call the sin_series*
 * function to save the value in the file.                                                *
 *****************************************************************************************
 */
int main(){
    std::ofstream my_file                   ; /*  Output file stream */
    std::string ini = "exp_series_file_v1_" ; 
    std::string txt = ".txt"                ;
    int i=1                                 ;
    for(int i=1;  i<=10;  i++){
        std::string final_name  = ini + std::to_string(i) + txt;
        std::ofstream my_file1              ;
        my_file1.open(final_name)           ;
        double x = 0.1*i                         ;
        std::cout <<  std::fixed            ;
        std::cout <<  std::setprecision(7)  <<  x <<  std::endl ;
        for (int i=1; i<=20;  i++){
//            my_file <<  std::setprecision(7)  <<  i <<  "\t"  <<  abs(exp_series(i,x)-exp_series(2*i,x)) <<  std::endl;
            my_file1 <<  std::setprecision(7)  <<  i <<  "\t"  <<  abs((exp_series(i,x)-exp_series(2*i,x))/exp_series(2*i,x)) <<  std::endl;
//            my_file1 <<  std::setprecision(7)  <<  i <<  "\t"  <<  abs((exp_series(i,x)-exp(x))/exp(x)) <<  std::endl;
        }
    }
    return(0);
}
