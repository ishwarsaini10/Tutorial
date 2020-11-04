
// Name     - Ishwar Singh
// Purpose  - Calculation of RoundOff errors in the solution of quadratic equation
// Email    - ishwarsaini10@gmail.com


#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<math.h>

void quad(float a, float b, int n){
/*    float a = 1.0     ;
    float b = 100000  ;
    float c = 1       ;
*/
//    std::ofstream  myfile  ;
//    myfile.open("quadratic2.txt")     ;
    std::cout <<  std::setprecision(7)  <<  std::setw(10);
    float c   = 1.0*pow(10,-n)               ;
    float d   = sqrt(pow(b,2)-4.0*a*c);
    float x1  = (-b+d)/(2*a)          ;
    float x2  = (-b-d)/(2*a)          ;
    float y1  = (-2*c)/(b+d)          ;
    float y2  = (-2*c)/(b-d)          ;
//    std::cout <<  "a  = " <<  a <<  "\t b = " <<  b <<  "\t c = " <<  c <<  std::endl ;
//    std::cout << "a  = " <<  a <<  "\t b = " <<  b <<  "\t c = " <<  c << "\t"  << x1  <<  " (  " <<  y1  <<  " ) or  " <<  x2  <<  " ( "<< y2  <<  " )"  <<  std::endl;
    std::cout <<  a <<  "\t"  <<  b << "\t" << c << "\t"  << x1  <<  "\t (  " <<  y1  <<  " )\t or  \t" <<  x2  <<  " \t( "<< y2  <<  " )\t"  <<  std::endl;
//    myfile <<  x1  <<  "(  " <<  y1  <<  " ) or  " <<  x2  <<  " ( "<< y2  <<  " )"  <<  std::endl;

//    std::cout <<  std::setprecision(7)  <<   "x1=" <<  x1  <<  std::endl;
//    std::cout <<  std::setprecision(7)  <<  "x2=" <<  x2  <<  std::endl;

}

int main(){
    int m = 1         ;
    std::ofstream  myfile  ;
    myfile.open("quadratic2.txt")     ;
    for(m = 1 ; m <=  5; m++){
        quad(1.0  , 1.0,  m);
    }
    myfile.close();
return(0);
}
