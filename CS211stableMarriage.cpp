/*
	Kayla Washington-Tapia
	CSCI 211 21D
	Assignment 8
*/
#include<iostream>
using namespace std;

bool ok(int q[], int col) { // Finish this code
	static int mp[3][3] = { { 0,2,1 },  	 // Man#0's preferences
							{ 0,2,1 },		// Man#1's preferences
							{ 1,2,0 } };	// Man#2's preferences
						
	static int wp[3][3] = { { 2,1,0 },		// Woman#0's preferences
							{ 0,1,2 },		// Woman#1's preferences
							{ 2,0,1 } };	 // Woman#2's preferences
	for(int i=0;i<col;i++){
		//checks whether the preferences are greater than their own spouses or whether all prefernces are met
		if((q[i]==q[col])||
		(mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i]<wp[q[col]][col])||
		(mp[col][q[i]]<mp[col][q[col]] && wp[q[i]][col]<wp[q[i]][i])){
			return false;
		}
	}
	return true;
}

void print(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
	for(int i=0;i<3;i++){
		cout<<"\n"<<i<<"\t"<<q[i]<<"\n";
	}
	//Finish this print function
}


int main() {
	//Write the main function.
	//The main function is exactly the same as 1D Queens. EXCEPT the array size is different.
	int q[3];
	int c=0;
	q[0]=0;
	int k=0;
	while(true){
		while(c<3){               //for columnns
			while(q[c]<3){        //for rows
				while(c>=0){      //next column
					c++;
					if(c==3){
						print(q);
						c--;
					}
					else{
						q[c]=-1;
					}
					while(c>=0){   //next row
						q[c]++;
						if(q[c]==3){
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