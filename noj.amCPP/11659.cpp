#include<iostream>
#include<stdio.h>
using namespace std;

int main(void){
    int n=0,m=0,tmp=0,a=0,b=0;

    //cin>>n>>m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++){
        //cin>>tmp;
        scanf("%d",&tmp);
        if(i!=0) arr[i]=arr[i-1]+tmp;
        if(i==0) arr[i]=tmp;
    }
    /*cout<<"\n";
    for(int i=0;i<n;i++){
       cout<<" "<<arr[i]<<" ";
    }
    cout<<"\n";*/
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        if(a==1){
            printf("%d\n",arr[b-1]);
            //cout<<arr[b-1]<<"\n";
        }
        else{
            
            //cout<<arr[b-1]<<"-"<<arr[a-2]<<"\n";
            //cout<<arr[b-1]-arr[a-2]<<"\n";
            printf("%d \n",arr[b-1]-arr[a-2]);
        }
        
        
    }
    return 0;
}