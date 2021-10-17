#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000000];
int minr = 2100000000;
int main(void) {
    int N, K, cnt = 0, e = 0, s = 0;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    while (s < N) {
        if (cnt < K && e < N) {
            if (arr[e] == 1) {
                e++;
                cnt++;
            }
            else if (arr[e] == 2) {
                e++;
            }
        }

        if (cnt > K) {
            if (arr[s] == 1) {
                s++;
                cnt--;
            }
            else if (arr[e] == 2) {
                s++;
            }
        }

        if (cnt == K) {
            if (e - s < minr) {
                minr = e - s;
            }
            if (arr[s] == 1) {
                cnt--;
            }
            s++;
        }
        else if (e == N )
            s++;

    }
    if (minr == 2100000000) {
        cout << -1;
    }
    else {
         cout << minr << "\n";
    }
   
    return 0;
}