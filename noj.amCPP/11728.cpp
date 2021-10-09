#include <stdio.h>
#include<algorithm>
using namespace std;

int main(void){
    int a,b;
    scanf("%d%d",&a ,&b);
    int ar1[a+b];
    //int arf[a+b];
    for(int i=0;i<a+b;i++){
        scanf("%d",&ar1[i]);
    }
    sort(ar1,ar1+a+b);
    for(int i=0;i<a+b;i++){
        printf("%d ",ar1[i]);
    }
    return 0;
}
/*
#include <iostream>
#include<algorithm>
using namespace std;

int main(void){
    int a,b;
    cin>>a>>b;
    int ar1[a+b];
    //int arf[a+b];
    for(int i=0;i<a+b;i++){
        cin>>ar1[i];
    }
    sort(ar1,ar1+a+b);
    for(int i=0;i<a+b;i++){
        cout<<ar1[i];
    }
    return 0;
}
*/