/*
	Kayla Washington Tapia
	October 1st, 2021
	CSCI211 21D
	2D 8 Queens
*/

#include <iostream>;
using namespace std;

int main(){
	
	//initialization
	int q[8][8]={};
	int r =0, c=0, s=0;
	
	//placing first queen in upper left corner
	q[r][c]=1;
	
	Nc: //next column
	c++;
	//will print if passed col
	if(c==8)goto print;
	//if it doesnt print it'll start again from top of column
	r=-1;
	
	Nr: //next row
	r++;
	if(r==8) goto backtrack;
	//row
	for(int i=0;i<c;i++){
		if(q[r][i]==1) goto Nr;
	}
	//up diagonal
	for(int i=0;((r-i)>=0 && (c-i)>=0);i++){
		if(q[r-i][c-i]==1) goto Nr;
	}
	//down diagonal
	for(int i=0;((r-i)<8 && (c-i)>=0);i++){
		if(q[r+i][c-i]==1) goto Nr;
	}
	q[r][c]=1;
	goto Nc;
	
	backtrack: //checks previous column
		c--;
		//if you go beyond the chess board
		if(c==-1){
			return 0;
		}
		//assigns r to the row with queen
		r=0;
		while(q[r][c]!=1){
			r++;
		}
		//deletes current queen
		q[r][c]=0;
		goto Nr;
		
	print:
		cout<<"Solution number :"<<++s<<endl;
		//board is printed out
		for (int i = 0; i < 8; i++)
		{
        	for (int j = 0; j < 8; j++)
        	{
            cout << q[i][j] << " ";
        	}
        cout << endl;
    	}
    	cout<<endl;
    	goto backtrack;

}