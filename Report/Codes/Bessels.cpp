/*
 * Name - Ishwar Singh
 * Aim  - To calculate the values and errors in Bessels functions using recursion relations.
 * Date - 08.11.2020
 * Emai - isingh@fnal.gov
*/

// C++ Directives
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cfloat>
#include<iomanip>
#include<fstream>

float bessels_up (float x, int l){
    int s = 25  ;
    float a  = sin(x)/x ;
    float b  = (sin(x)/pow(x,2))-cos(x)/x ;
    float j[s]  = {a,b}  ;
    for(int k = 1;  k<s-1;  k++){
        j[k+1]  = ((2*k+1)/x)*j[k]-j[k-1];
    }
    //float scale = (sin(x)/x)/j[0]; 
    return j[l] ;
}

float bessels_down (float x, int l){
    int s = 25  ;
//    float a  = sin(x)/x ;
//    float b  = (sin(x)/pow(x,2))-cos(x)/x ;
    float j[s]  = {}  ;
          j[23] = 1.0 ;
          j[24] = 1.0 ;
    for(int k = s-2;  k>0;  k--){
        j[k-1]  = ((2*k+1)/x)*j[k]-j[k+1];
    }
    float scale = (sin(x)/x)/j[0]; 
    return j[l]*scale ;
}


int main(){
    float x ;
    int i   ;
    std::ofstream my_file;
    my_file.open("Bessels.txt");
    for(int i =  0;  i<=25;  i++){
        x = 1.0;
        my_file <<  std::fixed  <<  std::setprecision(7)  <<  i <<  "\t"  <<  bessels_up(x,i) <<  "\t"  <<  bessels_down(x,i) <<  "\t"  << abs(bessels_up(x,i)-bessels_down(x,i))/(abs(bessels_up(x,i))+abs(bessels_down(x,i))) <<    std::endl;
    }

    return 0;
}
