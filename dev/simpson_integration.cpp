// CPP program for simpson's 1/3 rule 
#include <iostream> 
#include <fstream> 
#include <math.h> 
#include <iomanip> 
using namespace std; 
  
// Function to calculate f(x) 
float func(float x) 
{ 
    return exp(-x); 
} 
  
// Function for approximate integral 
float simpsons_(float ll, float ul, int n) 
{ 
    // Calculating the value of h 
    float h = (ul - ll) / n; 
  
    // Array for storing value of x and f(x) 
    float x[300], fx[300]; 
  
    // Calculating values of x and f(x) 
    for (int i = 0; i <= n; i++) { 
        x[i] = ll + i * h; 
        fx[i] = func(x[i]); 
    } 
  
    // Calculating result 
    float res = 0; 
    for (int i = 0; i <= n; i++) { 
        if (i == 0 || i == n) 
            res += fx[i]; 
        else if (i % 2 != 0) 
            res += 4 * fx[i]; 
        else
            res += 2 * fx[i]; 
    } 
    res = res * (h / 3); 
    return res; 
} 
  
// Driver program 
int main() 
{ 
    float lower_limit = 0; // Lower limit 
    float upper_limit = 1; // Upper limit 
    int n ; // Number of interval 
    std::ofstream my_file ;
    float true_val  = 0.63212055    ;
    my_file.open("simpson_v1.txt")  ;

    for(n=2;  n<=300;  n+=4){
    my_file <<  std::setprecision(7)<< n << "\t"  << abs((true_val - simpsons_(lower_limit, upper_limit, n))/true_val)  <<  std::endl; 
    }
    return 0; 
} 
