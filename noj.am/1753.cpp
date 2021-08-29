#include<iostream>
#include<vector>
#include <queue>
using namespace std;
#define INTS 2147483647

priority_queue<pair<int, int>> pq;
vector<pair<int, int>> vec[300001];
int minD[300001];


void dijst(int strt){
   
    minD[strt]=0;
    pq.push(make_pair(0,strt));
    while (pq.empty()==false){
        int current = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        for (int i = 0; i < vec[current].size(); i++) {
            int next = vec[current][i].second;
            int nextDist = dist + vec[current][i].first;
            if (nextDist < minD[next]) {

                minD[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
}

int main(void){
     for(int i=0;i<300001;i++){
        minD[i]=INTS;
    }
    int V,E,K;
    int tmpu,tmpv,tmpw;
    cin>>V>>E>>K;
    for(int i=0;i<E;i++){
        cin>>tmpu>>tmpv>>tmpw;
        vec[tmpu].push_back(make_pair(tmpw,tmpv));
    }
    dijst(K);
    for(int i=1;i<V+1;i++){
        if(minD[i]==2147483647){
            cout<<"INF"<<"\n";
            continue;
        }
        cout << minD[i] << "\n";
    }
    return 0;
}