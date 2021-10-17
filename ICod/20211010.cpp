#include<iostream>
using namespace std;
int INF = 10000001;


int main(void) {
    int nodecnt = 0, m = 0, ta, tb, tc;
    cin >> nodecnt;
    int d[101][101];
    for (int i = 1; i <= nodecnt; i++) {
        for (int j = 1; j <= nodecnt; j++) {
            if (i == j) d[j][i] = 0;
            else d[j][i] = INF;
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> ta >> tb >> tc;
        if(d[ta][tb]>tc)  d[ta][tb] = tc;
    }
    for (int i = 1; i <= nodecnt; i++) {
        for (int j = 1; j <= nodecnt; j++) {
            for (int k = 1; k <= nodecnt; k++) {
                if (d[j][i] + d[i][k] < d[j][k]) {
                    d[j][k] = d[j][i] + d[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= nodecnt; i++) {
        for (int j = 1; j <= nodecnt; j++) {
            if (d[i][j] == INF) cout << 0<<" ";
            else cout << d[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}