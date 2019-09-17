#include<iostream>
#include <cmath>
#include<chrono>
using namespace std::chrono;
using namespace std;



double function(double x)
{
  return pow(x,3)-cos(x+3)+50;
}

double derivative(double x) 
{ 
    return 3*pow(x,2)+sin(x+3);
} 


void newton(double x) 
{ 
    int iter=0;
    double h = function(x) / derivative(x); 
	auto start = high_resolution_clock::now(); 
    while (abs(h) >= 0.0001) 
    { 
        h = function(x)/derivative(x);  
        x = x - h;
        iter+=1; 
    } 

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 

  
    cout << "The value of the root is : " << x<<endl;
    cout << "The number of iterations : " << iter<<endl; 
    cout << duration.count()<<" microseconds"<< endl; 
	
} 


int main() 
{ 
    double x = -10;
    newton(x); 
    return 0; 
} 

	
