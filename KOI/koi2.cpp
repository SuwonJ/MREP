#include <iostream>
using namespace std;
long long wd=0,tm[200000]={},tmw[200000]={},wk=0,up=0;


void upp(int it){
    tmw[it]+=tmw[tm[it]];
    if(tm[it]>1) upp(tm[it]);
}

int main(void) {
    int n;
    long long max=0,maxx=0;
    cin>>n;
    for(long long i=1;i<n;i++){
        cin>>wk>>up;
        upp(i);
        tmw[i]+=wk;
    }
    /*for(int i=0;i<n;i++){
       tm
    }*/
    for(long long i=2;i<n+1;i++){
        if(tmw[i]>max){
            if(max>maxx){
                maxx=max;
            }
            max=tmw[i];
        }
        else if(tmw[i]>maxx){
            maxx=tmw[i];
        }
    }
    cout<<max+maxx;
}
