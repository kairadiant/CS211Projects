/*
	Kayla Washington-Tapia
	CSCI 211 21D
	Assignment 13
*/
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c){
	for(int i=0;i<c;i++){
		if(q[i]==q[c]||(c-i)==abs(q[c]-q[i])){
			return false;
		}
	}
	return true;
}
// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
   int* q = new int[n]; //dyanmic array declared
   q[0] = 0;
   int c = 0, solutions = 0; //column and solution count declared
   
   while (c >= 0) {
      if (c == n - 1) {
         ++solutions;
         --c;
      }
      else
         q[++c] = -1;
      while (c >= 0) {
         ++q[c];
         if (q[c] == n)
            --c;
         else if (ok(q, c))
            break;
      }
   }
   delete[] q; //array is deleted afterwards
   return solutions;
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n"; //solutions are printed out
   return 0;
}
   