#include<iostream>
#include<stdio.h>
using namespace std;
long long arr[1025][1025];
long long sum[1025][1025];

int main(void) {
    int summ = 0, a = 0, b = 0, tmpa, tmpb, tmpc, tmpd, tmpf;
    scanf("%d %d", &a, &b);
    //cin >> a >> b;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++) {
            scanf("%d", &arr[i][j]);
            //cin >> arr[i][j];
        }
    }

    //cout << "\n**********************************\n\n";

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++) {
            sum[i][j] = arr[j][i] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = 0; i < b; i++) {
        scanf("%d %d %d %d", &tmpa, &tmpb, &tmpc, &tmpd);
        //cin >> tmpa >> tmpb >> tmpc >> tmpd;
        printf("%d\n", sum[tmpd][tmpc] - sum[tmpd][tmpa - 1] - sum[tmpb - 1][tmpc] + sum[tmpb - 1][tmpa - 1]);
        //cout << sum[tmpd][tmpc] - sum[tmpd][tmpa-1] - sum[tmpb-1][tmpc] + sum[tmpb-1][tmpa-1] << "\n";
    }
    /*
    for(int i=0;i<=a;i++){
        for(int j=0;j<=a;j++){
            cout<<sum[i][j]<<"  ";
        }
        cout<<"\n";
    }
    
    */
    return 0;
}