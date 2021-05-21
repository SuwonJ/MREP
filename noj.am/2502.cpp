#include<stdio.h>
#include<iostream>
using namespace std;

int main(void) {
    int d, k, a = 1, b = 1,at,bt;
    cin >> d >> k;
    int fi[33] = {a,b};
    for (int i = 0; i < 30; i++) {
        fi[i + 2] = fi[i] + fi[i + 1];
    }
    /* for (int i = 0; i < 30; i++) {
        cout<<fi[i]<<"\n";
    }
    for (int i = 0; i < 30; i++) {
        cout << fi[i]<<endl;
    }*/ 
   
    at = fi[d - 3]; bt = fi[d - 2];
    //cout<<at<<"  "<<bt<<endl;
    for(int i = 0; i < 300; i++) {
        if((k-at * i)%bt == 0) {
            cout <<i<<"\n"<<(k-at*i)/bt<<"\n";
            return 0;
        }
    }
}