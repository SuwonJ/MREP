#include<iostream>
#include<string.h>
using namespace std;
int stack[100000];
int i;
int topp = 0;

int push(int x){
    stack[topp] = x;
    topp++;
    return 0;
}
int pop() {
    if (topp == 0) {
        return(-1);
    }
    int tmp;
    tmp = stack[topp-1];
    stack[topp-1] = 0;
    topp--;
    
    return tmp;
}
int size() {
    return topp;
}
int empty() {
    return (topp==0);
}
int top() {
    if (topp == 0) {
        return(-1);
    }
    return (stack[topp-1]);
}


int main(void) {
    push(5);
    push(3);push(7);push(4);
    cout<<pop()<<"\n";
    push(9);
    cout<<pop()<<"\n";
    cout<<pop()<<"\n";
    cout<<pop()<<"\n";
    cout<<pop()<<"\n";
    return 0;
}