#include <stdio.h>

int arr[200000];
int sum[200000];
int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&arr[i]);

    }
    sum[0] = arr[0];
    for(int i=1;i<N;i++){
        sum[i] = sum[i-1] + arr[i];
    }
    int sum1 = sum[N-1] - sum[0];
    int ans = 0;
    for(int i=1;i<N-1;i++){
        int sum2 = sum1 - arr[i] + sum[N-1] - sum[i];
        if(ans < sum2){
            ans = sum2;
        }
    }
    sum1 = sum[N-2];

    for(int i=N-2;i>0;i--){
        int sum2 = sum1 - arr[i] + sum[i-1];
        if(ans < sum2){
            ans = sum2;
        }
    }

    sum1 = sum[N-1] - arr[0] - arr[N-1];


    for(int i=1;i<N-1;i++){
        if( ans < sum1 + arr[i]){
            ans = sum1 + arr[i];
        }
    }
    printf("%d\n",ans);

    return 0;
}