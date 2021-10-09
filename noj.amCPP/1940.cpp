#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int s=0,e=0,sum=0,cnt=0;
    int n,x;
    cin>>n>>x;
    e=n-1;
    int arr[n]={};
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    //for(s=0;s<n;s++){
    while(s<e){
        if(arr[s]+arr[e]==x){
            cnt++;
            
            e--;s++;
        }
        else if(arr[s]+arr[e]>x){
            e--;
        }
        else if(arr[s]+arr[e]<x){
            s++;
        }
    }  
    //}
    cout<<cnt<<"\n";
    return 0;
}