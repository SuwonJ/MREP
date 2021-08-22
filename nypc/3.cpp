#include<iostream>
using namespace std;

int main(void){
    int m,f,n;
    cin>>m>>f>>n;
    if(n<f){
        cout<<"1"<<"\n";
        return 0;
    }
    cout<<(n/m)+1<<"\n";
    return 0;
}