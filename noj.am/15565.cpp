#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int N,K,i,cnt=0,e=0,s=0,minr=0;
    cin>>N>>K;
    int arr[N]={};
    for(i=0;i<N;i++){
        cin>>arr[i];
    }
    i=0;
    while(s<N){
        if(cnt<K){
            if(arr[e]==1){
               e++;
               cnt++;
            }
            else if(arr[e]==2){
                e++;
            }
        }
        if(cnt>K){
            if(arr[s]==1){
               e++;
               cnt++;
            }
            else if(arr[e]==2){
                e++;
            }
        }
        if(cnt==K){
            minr=e-s;
        }
        i++;
        if(arr[e]==1){
            cnt++;
        }
        else if(arr[e]==2){
            e++;
        }
        if(cnt==K){
            if(arr[e]==1){
                cnt--;
            }
            s++;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}