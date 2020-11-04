

/*
Name  - Ishwar Singh
Aim   - Error analysis in series sum.
Email - ishwarsaini10@gmail.com
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

float series1(int n){
    int   i ;
    float t ;
    float s ;
    s = t = -1.0/2.0  ;
    for(i=1;  i<2*n;  i++){
        t*=-(pow((i+1),2))/(i*(i+2))  ;
        s+=t;
    }
    return(s);
}

float series2(int n){
    int   i   ;
    float t1  ;
    float t2  ;
    float s1  ;
    float s2  ;
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

float series3(int n){
    int   i ;
    float t ;
    float s ;
    s = t = 1.0/6.0  ;
    for(i=1;  i<n;  i++){
        t*=(n*(2*n+1))/((n+1)*(2*n+3));
        s+=t;
    }
    return(s);
}
int series_v3(){
    const int N = 10000     ;
    const int Nbins = 1000;       
    float     x_min = 0.0 ;
    float     x_max = 6.0 ;
    float     S1          ;
    float     n           ;      
    float s1_final        ;
    float s2_final        ;
    float s3_final        ;
    std::ofstream myfile  ;
    //myfile.open("series.txt");
    std::cout <<  std::setprecision(7) << std::setw(10) ;

    //TGraph  *graph  = new TGraph(N, );         
    TH1F *hist  = new TH1F("hist", "Error Analysis",  Nbins,  x_min,  x_max);

    for(int j=1;  j<=N; j++){
        s1_final  = series1(j);
        s2_final  = series2(j);
        s3_final  = series3(j);
        //std::cout <<  s1_final  <<  "\t"  <<  s2_final  <<  "\t"  <<  s3_final  <<  std::endl;
        //myfile <<  s1_final  <<  "\t"  <<  s2_final  <<  "\t"  <<  s3_final  <<  std::endl;

        S1 = TMath::Log10(TMath::Abs((s1_final-s3_final)/s3_final));
        n  = TMath::Log10(j);  
        hist  ->  Fill(n, S1);
    }
    
    hist  ->  Draw();

    return 0;
}
