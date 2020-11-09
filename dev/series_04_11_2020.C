
/*
Name  - Ishwar Singh
Aim   - Error analysis in series sum.
Email - ishwarsaini10@gmail.com
Date  - 04.11.2020
*/

/*C++ Directives*/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<fstream>

/* ROOT Directives  */
#include<TCanvas.h>
#include<TMath.h>
#include<TGraph.h>
#include<TH1F.h>

double series1(int n){
    int   i ;
    double t ;
    double s ;
    s = t = -1.0/2.0  ;
    for(i=1;  i<2*n;  i++){
        t*=-(pow((i+1),2))/(i*(i+2))  ;
        s+=t;
    }
    return(s);
}

double series2(int n){
    int   i   ;
    double t1  ;
    double t2  ;
    double s1  ;
    double s2  ;
    s1  = t1  = 1.0/2.0   ;
    s2  = t2  = 2.0/3.0   ;
    for(i=1;  i<n;  i++){
        t1*=((2*i+1)*i)/((2*n-1)*(n+1))       ;
        t2*=((2*i+2)*(2*i+1))/((2*i+3)*(2*i)) ;
        s1+=t1;
        s2+=t2;
    }
    return(s2-s1);
}

double series3(int n){
    int   i ;
    double t ;
    double s ;
    s = t = 1.0/6.0  ;
    for(i=1;  i<n;  i++){
        t*=(n*(2*n+1))/((n+1)*(2*n+3));
        s+=t;
    }
    return(s);
}
int series_04_11_2020(){
    const int N = 10000     ;
    const int Nbins = 1000;       
    double     x_min = 0.0 ;
    double     x_max = 6.0 ;
    double     S1          ;
    double     n           ;      
    double s1_final        ;
    double s2_final        ;
    double s3_final        ;
    std::ofstream myfile  ;
    myfile.open("series_04_11_2020.txt");
    std::cout <<  std::setprecision(7) << std::setw(10) ;

    for(int j=1;  j<=N; j++){
        s1_final  = series1(j);
        s2_final  = series2(j);
        s3_final  = series3(j);
        myfile <<  j <<  "\t"  <<  TMath::Log10(TMath::Abs((s1_final-s3_final)/s3_final))  <<  std::endl;
  
        }
    

    return 0;
}
