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
int main(){
    int N;
    float s1_final  ;
    float s2_final  ;
    float s3_final  ;
    std::ofstream myfile;
    myfile.open("series1.dat");
    std::cout <<  std::setprecision(7) << std::setw(10) ;

    for(int N=1;  N<=10000; N++){
        s1_final  = series1(N);
        s2_final  = series2(N);
        s3_final  = series3(N);
        std::cout <<  s1_final  <<  "\t"  <<  s2_final  <<  "\t"  <<  s3_final <<"\t" <<  log10(N) << "\t" << log10(abs((s1_final-s3_final)/s3_final)) <<  std::endl;
        //myfile <<  s1_final  <<  "\t"  <<  s2_final  <<  "\t"  <<  s3_final  <<  std::endl;

        //myfile <<  log10(N)  <<  "\t"  <<  log10(abs((s1_final-s3_final)/s3_final))  <<  std::endl;
        //cout <<  log10(N)  <<  "\t"  <<  log10(abs((s1_final-s3_final)/s3_final))  <<  std::endl;
    }
    myfile.close();
    return 0;
}
