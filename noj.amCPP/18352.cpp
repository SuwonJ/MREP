#include<iostream>
#include<vector>
#include<queue>
#define INTS 2147483647
using namespace std;
int minD[1000001];

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> vec[1000001];

void dijst(int strt){
    minD[strt]=0;
    pq.push(make_pair(0,strt));
    while (pq.empty()==false){
        int cur = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i].second;
            int nxtD = dist + vec[cur][i].first;
            if (nxtD < minD[next]) {

                minD[next] = nxtD;
                pq.push(make_pair(-nxtD, next));
            }
        }
    }
}

int main(void){
    int N,M,K,X;
    cin>>N>>M>>K>>X;
    int tmpa,tmpb;
    for(int i=0;i<N+1;i++){
        minD[i]=INTS;
    }
    
     for(int i=1;i<M+1;i++){
         int tmpu,tmpv;
        cin>>tmpu>>tmpv;
        vec[tmpu].push_back(make_pair(1,tmpv));
    }
    dijst(X);
    int nx=1;
    for(int i=1;i<1000001;i++){
        if(minD[i]==K){
            nx=0;
            cout<<i<<"\n";
        }
    }
    if(nx==1) cout<<-1<<"\n";

    return 0;
}