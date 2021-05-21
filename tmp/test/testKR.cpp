#include<stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;


char func(){
    return('안');
}
char funcpp(){
    return('녕');
}

int main(){
    system("chcp");
    cout<<func();
    cout<<endl;
     cout<<funcpp();
    cout<<endl;
    system("pause");
    return 0;
}