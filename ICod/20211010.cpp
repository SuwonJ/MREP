#include<iostream>
using namespace std;
int INF=2147483647;
int arr[4][4]=
{
    {0,5,INF,8},
    {7,0,9,INF},
    {2,INF,0,4},
    {INF,INF,3,0}
};


int main(void){
    int nodecnt;
    cin>>nodecnt;
    int d[nodecnt][nodecnt];
    for(int i=0;i<nodecnt;i++){
        for(int j=0;j<nodecnt;i++){
            d[i][j]=arr[i][j];
        }
    }
    for(int i=0;i<nodecnt;i++){
        for(int j=0;j<nodecnt;i++){
            for(int k=0;k<nodecnt;k++){
                if(d[j][i]+d[i][k]<d[j][k]){
                    d[j][k]=d[j][i]+d[i][k];
                }
            }
        }
    }
    for(int i=0;i<nodecnt;i++){
        for(int j=0;j<nodecnt;j++){
            cout<<d[i][j];
        }
    }
    return 0;
}