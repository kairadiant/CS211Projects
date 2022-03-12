/*
Kayla Washington-Tapia
Assignment 7: 8 Numbers in a Cross
10.22.2021
CSCI 211 21D
*/

#include<iostream>
using namespace std;

void print(int q[]){ //outputs solution in cross format
	static int s=0;
	cout<<"Solution "<<++s<<endl;
	cout<<" "<<q[1]<<q[6]<<endl;
	cout<<q[0]<<q[2]<<q[5]<<q[7]<<endl;
	cout<<" "<<q[3]<<q[4]<<endl;
}

bool okay(int q[],int c){ //checks to make sure numbers in row are okay
	static int helper[8][5]={
	{-1},
	{-1},
	{0, 1, -1},
	{0, -1},
 	{0, 2, 3, -1},
 	{0, 2, 3, -1},
 	{0, 1, 2, 4, -1},
	{0, 1, 2, 5, -1},
	};
	
	for(int i=0;i<c;i++){
		if(q[i]==q[c]){
			return false;
		}
	}
	for(int i=0;helper[c][i]!=-1;i++){
		if(abs(q[c]-q[helper[c][i]])==1){
			return false;
		}
	}
	return true;
}

int main(){
	int q[8],place=0;
	q[place]=1;
	
	while(place>=0){
		++place;
		if(place==8){ //if all solutions were found
			print(q);
			place--; //backtrack
			
		}
		else{
			q[place]=0;
		}
		while(place>=0){
			++q[place];
			if(q[place]>8){ //if no solutions in row
				place--;
			}
			else{
				if(okay(q,place)){ //if number placement is okay
					break;
				}
			}
		}
	}
}