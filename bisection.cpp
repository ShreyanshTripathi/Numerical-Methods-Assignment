#include<iostream>
#include <cmath>
#include<chrono>
using namespace std::chrono;
using namespace std;


double function(double x)
{
  return pow(x,3)-cos(x+3)+50;
}


void bisection(double a, double b) 
{ 
    if (function(a) * function(b) >= 0) 
    { 
        cout << "Give correct a and b"<<endl; 
        return; 
    } 
  
    double c = a;
    int iter=0; 
    auto start = high_resolution_clock::now(); 
    while ((b-a) >= 0.0001) 
    {  
        c = (a+b)/2; 
	iter=iter+1; 
        if (function(c) == 0.0)
        {
        	break;
        } 
        else if (function(c)*function(a) < 0)
        {
        	b = c;
        } 
             
        else
        {
            a = c; 
        } 
    } 

    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 
  cout << "The value of root is : " << c<<endl;
  cout << "No of Iterations : " << iter<<endl;
  cout << duration.count()<<" microseconds"<< endl; 
}



int main() 
{   	
	double a,b;
	cout<<"Enter 1 interval value"<<endl;
	cin>>a;
	cout<<"Enter 2 interval value"<<endl;
	cin>>b;
    bisection(a, b); 
    return 0; 
}

	
