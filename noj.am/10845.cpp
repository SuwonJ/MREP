#include<stdio.h>
#include<iostream>
#include<string.h>
#include<windows.h>

using namespace std;
int queue[100000];
int frnt = -1;
int rear = -1;

void push(int x) {
    rear++;
    queue[rear] = x;
}
int empty() {
    if (rear - frnt < 1) return 1;
    else return 0;
}
int pop() {
    if (empty()==1) return -1;
    else{
        frnt++;
        return queue[frnt];
    } 
}
int size() {
    return rear-frnt;
}

int front() {
    if (empty() == 1) return -1;
    else return queue[frnt+1];
}
int back() {
    if (empty() == 1) return -1;
    else return queue[rear];
}
int main() {
    char inp[100] = {};
    int x = 0;
    int i, rout;
    scanf("%d", &rout);

    for (i = 0; i < rout; i++) {
        scanf("%s", inp);
        if (strcmp(inp, "push") == 0) {
            scanf("%d\n", &x);
            push(x);
        }
        else if (strcmp(inp, "pop") == 0) {
            printf("%d\n", pop());
        }
        else if (strcmp(inp, "size") == 0) {
            printf("%d\n", size());
        }

        else if (strcmp(inp, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(inp, "front") == 0) {
            printf("%d\n", front());
        }
        else if (strcmp(inp, "back") == 0) {
            printf("%d\n", back());
        }
    }
    return 0;
}
