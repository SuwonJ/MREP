#include<stdio.h>
#include<iostream>
#include<windows.h>

using namespace std;

int main() {
    int n, i, r, cnt=0, nn, j, ac = 0;
    cin >> r;
    for (i = 0; i < r; i++) {
        cin >> n;
        if (n == 1) {
            continue;
        }
        nn = n;
        for (j = 1; j < nn; j++) {
            if (n % j == 0) {
                cnt++;
                
            }
        }
        if (cnt > 2) {
            ac++;
        }
        cnt = 0;
    }
    cout << ac << endl;
    system("pause");
    return 0;
}