#include<iostream>
using namespace std;
int n;
int rarr[1001][3];
int parr[1001][3];
int min(int a,int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
int main(void){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>parr[i][0]>>parr[i][1]>>parr[i][2];
    }
    for(int i=1;i<=N;i++){
        rarr[i][0]=min(rarr[i-1][1],rarr[i-1][2])+parr[i][0];
        rarr[i][1]=min(rarr[i-1][0],rarr[i-1][2])+parr[i][1];
        rarr[i][2]=min(rarr[i-1][0],rarr[i-1][1])+parr[i][2];
    }
    cout<<min(rarr[N][0],min(rarr[N][1],rarr[N][2]))<<"\n";
   
}