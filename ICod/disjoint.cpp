#include<iostream>
using namespace std;

int parent[9];

int getP(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=getP(parent[x]);
}
void unionP(int a, int b){
    int aPar=getP(a);
    int bPar=getP(b);
    if(aPar<bPar){
        parent[bPar]=a;
    }
    else{
        parent[aPar]=b;
    }
}
int findP(int a,int b){
    int aPar=getP(a);
    int bPar=getP(b);

    if(aPar==bPar){
        return 1;
    }
    else{
        return 0;
    }
}
int main(void){
    unionP(1,2);
    unionP(2,3);
    unionP(3,4);
    unionP(5,6);
    unionP(6,7);
    cout<<findP(1,5);
}
