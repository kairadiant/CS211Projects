/*
	Kayla Washington-Tapia
	CSCI 211 21D
	Assignment 12
*/
#include<iostream>
using namespace std;

typedef double (*FUNC)(double);

double integrate(FUNC f, double a, double b){
   double sum=0;
   for(double x=a;x<=b;x+=0.0001){ //sum of the area is calculated
      sum+=f(x)*0.0001;
   }
   return sum;
}

double line(double x){
   return x;
}

double square(double x){
   return x*x;
}

double cube(double x){
   return x*x*x;
}

int main(){
  cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;     // 12
   cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; // 41.3333
   cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;   // 156
  return 0;
}