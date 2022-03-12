#include <iostream>
using namespace std;

int main(){
	bool hold=false;
	int num, square, newnum;
	num=1;
	while(hold!=true){
		square=num*num;
		cout<<num<<"*"<<num<<"="<<square<<endl;
			newnum=square%100;
			if(newnum/10%2!=0 &&newnum%10%2!=0){
				cout<<"The perfect square: "<<square<<" of "<<num<<endl;
				hold=true;
			}
		num++;
	}
	return 0;
}