#include<iostream>
using namespace std;

int main(void){
    int n=5,m=5, cnt=0, s=0, e=0, sum=0;
    int arr[6]={1,2,3,2,5};

    for(s=0;s<n;s++){
        while(sum<m&&e<n){
            sum+=arr[e];
            e++;
        }
        if(sum==m){
            cnt++;
        }
        sum-=arr[s];
    }
    cout<<cnt<<"\n";
    return 0;
}