/*
	Kayla Washington-Tapia
	CSCI 211 21D
	Assignment 6
	OCT.15.2021
*/


#include<iostream>
using namespace std;

bool ok(int q[], int c){
	for(int i=0;i<c;i++){
		if(q[i]==q[c]||(c-i)==abs(q[c]-q[i])){
			return false;
		}
	}
	return true;
}

void print(int q[]){
	static int s=1;
	cout<<"Solution "<<s++<<": "<<endl;
	for(int i=0;i<8;i++){
		cout<<q[i]<<" ";
	}
	cout<<endl;
}



int main(){
	int q[8];
	int c=0;
	q[0]=0;
	
	while(true){
		while(c<8){               //for columnns
			while(q[c]<8){        //for rows
				while(c>=0){      //next column
					c++;
					if(c==8){
						print(q);
						c--;
					}
					else{
						q[c]=-1;
					}
					while(c>=0){   //next row
						q[c]++;
						if(q[c]==8){
							c--;
						}
						else if(ok(q,c)){
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}