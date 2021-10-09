#include<iostream>
#include <algorithm>

using namespace std;

int main(void){
    int N=0,s=0,e=0,min=2123456789,ss,se;
    cin>>N;
    e=N-1;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr, arr+N);
    while(s<e){
        int tmp;
        tmp=arr[s]+arr[e];
        if(tmp==0){
            cout<<arr[s]<<" "<<arr[e];
            return 0;
        }
        if(tmp<0){
            if(min>=tmp*-1){
                min=tmp*-1;
                ss=arr[s];
                se=arr[e];
            }
            s++;
        }
        if(tmp>0){
            if(min>=tmp){
                min=tmp;
                ss=arr[s];se=arr[e];
            }
            e--;
        }
        
    }

cout<<ss<<" "<<se;



}