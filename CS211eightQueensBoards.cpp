/*
	Kayla Washington-Tapia
	CSCI 211 21D
	Assignment 10
*/
#include <iostream>
#include  <cmath>
#include <cstdlib>
using namespace std;

bool ok(int q[], int c){ //same ok function
	for(int i=0;i<c;i++){
		if(q[i]==q[c]||(c-i)==abs(q[c]-q[i])){
			return false;
		}
	}
	return true;
}

void print(int q[]){
	static int s=1;
	typedef char box[5][7];
	box bb, wb, bq, wq, *board[8][8];
	char w=char(219);
	
	for(int i=0;i<5;i++){
		for(int j=0;j<7;j++){
			if(j>0 &&j<6 && i>0 &&i<4){
				if(i==1){ //fills out row 2 of queen boxes
					if(j%2==1){
						bq[i][j]=' ';
						wq[i][j]=w;
					}
					else{
						bq[i][j]=w;
						wq[i][j]=' ';
					}
				}
				else{//fills out the remaining portions of the queen shape
					bq[i][j]=' ';
					wq[i][j]=w;
				}
			}
			else{ //fills out the background of q
				bq[i][j]=w;
				wq[i][j]=' ';
			}//defines regular background squares
			wb[i][j]=w;
			bb[i][j]=' ';
		}
	}
	
	for(int r=0;r<8;r++){ //creates the chess board
		for(int c=0;c<8;c++){
			if((r+c)%2==0)
				board[r][c]=&bb;
			else
				board[r][c]=&wb;
		}
	}
	
	for(int i=0; i<8; i++){ //places the correct queen when necessary 
		if((i+q[i])%2 == 0)
 			board[q[i]][i] = &wq;
		else
 			board[q[i]][i] = &bq;
	}
		
	
	cout<<"Solution #"<<s++<<":\n"; //upper border
	for (int i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";
   
   for(int i=0;i<8;i++){ //board is printed
        for(int k=0;k<5;k++){
			cout<<" "<<char(179); //print left border
            for(int j=0;j<8;j++)
                for(int l=0;l<7;l++)
                    cout<<(*board[i][j])[k][l];
            cout<<char(179)<<endl; // at end of line print bar and then newline
        }
	}
    //print lower border
    cout<<" ";
    for(int i=0;i<7*8;i++)
        cout<<char(196);
    cout<<endl;
   
   
}


int main(){
	int q[8];
	int c=0;
	q[0]=0;
	//same main function
	while(true){
		while(c<8){               //for columnns
			while(q[c]<8){        //for rows
				while(c>=0){      //next column
					c++;
					if(c==8){
					//	print(q);
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