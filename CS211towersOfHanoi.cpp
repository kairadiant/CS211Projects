/*
	Kayla Washington-Tapia
	CSCI 211 21D
	Assignment 11
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<int> t[3];
	int n=3, from=0, to=1, candidate=1;
	
	for(int i=n+1;i>0;i--)
		t[0].push_back(i);
	t[1].push_back(n+1);
	t[2].push_back(n+1);
	
	while(t[1].size()<n+1){
		cout<<"Transfer ring "<<candidate<<" from tower "<<from<<" to "<<to<<"\n"; //prints solution
		//moves from tower to tower by adding it to to tower and deleting from from tower
		t[to].push_back(candidate);
		t[from].pop_back();
		//from is defined as the index of the tower with the smallest ring that was not just moved
		if(t[(to+1)%3].back()>t[(to+2)%3].back())
			from=(to+2)%3;
		else
			from=(to+1)%3;
		candidate=t[from].back(); //candidate is the ring on top of the t[from] tower
		//to is defined as the closest tower that the candidate can be placed
		if(candidate>t[(from+1)%3].back()) 
			to=(from+2)%3;
		else 
			to=(from+1)%3;
	}
	return 0;
	
}