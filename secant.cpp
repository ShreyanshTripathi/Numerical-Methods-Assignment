
#include <iostream>
#include <math.h>
#include<chrono>
using namespace std::chrono; 
using namespace std;


double function(double x)
{
  return pow(x,3)-cos(x+3)+50;
}


void secant(double a,double b,double error)
{

  if (function(a) * function(b) > 0)
  {
    cout<< "Please enter correct points";
    return;
  }
  
int iter=0;
double c,d;
auto start = high_resolution_clock::now(); 
 
 do {
          c = (a*function(b)-b*function(a))/(function(b)-function(a));
          iter++;

          if(function(c) == 0)
          {
             break;
          }
                
          else
          {
            a=b;
            b=c;
            d = (a*function(b)-b*function(a))/(function(b)-function(a));
          }    
    }

    while(fabs(d-c)>=error);
    
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 

    cout<<"Root = "<<c<<endl;
    cout<<"No of Iterations:"<<iter<<endl;
    cout << duration.count()<<" microseconds"<< endl; 

}

int main()
{
    
  double a,b,error;

  cout << "Enter first point: ";
  cin >> a;

  cout << "Enter second point: ";
  cin >> b;

  cout << "Enter error: ";
  cin >> error;
  
  secant(a,b,error);

    return 0;
}
