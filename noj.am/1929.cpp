#include<iostream>
using namespace std;
int arr[2000001]={};
int main(void){
    long long s=0,r=0;
    cin>>s>>r;
    for(int i=2;i*i<=r;i++){
        if(arr[i]==0){
            for(int j=i*i;j<=r;j+=i){
                arr[j]=1;
            }
        }
    }
    for(int i=s;i<=r;i++){
       if(arr[i]==0&&i!=1) cout<<i<<"\n";
    }
    return 0;
}