#include <iostream>
using namespace std;

int main(void){
    int ra,rb,rc,ttl;
    cin>>ra>>rb>>rc>>ttl;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			for(int k=0;k<50;k++){
				if(ra*i+rb*j+rc*k==ttl){
					cout<<"1";
					return 0;
				}
			}
		}
	}
	cout<<"0 \n";
    return 0;
}
/*
5	5	
9	9	4
12	10	1
	12	2
	14	2
	15	1
	17	2
	19	2
	20	1
		

 */