#include<iostream>
#define INTS 2147483647
using namespace std;
#include <queue>
#include<vector>

int number = 6;

vector<pair<int, int>> v[1001];

int minD[1001];


void dijkstra(int start) {
    minD[start] = 0;

    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current = pq.top().second;

        int dist = -pq.top().first;
        pq.pop();
        if (minD[current] < dist) {
            continue;
        }

        for (int i = 0; i < v[current].size(); i++) {
            int next = v[current][i].first;
            int nextDist = dist + v[current][i].second;
            if (nextDist < minD[next]) {
                minD[next] = nextDist;
                pq.push(make_pair(-nextDist, next));
            }
        }
    }
}

int main(void) {
    for(int i=0;i<1001;i++){
        minD[i]=INTS;
    }
    //간선정보 입력
    int n,m,st,ed,cst;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>st>>ed>>cst;
        v[st].push_back(make_pair(ed,cst));
    }
    int S,E;
    cin>>S>>E;
    dijkstra(S);
    cout << minD[E] << "\n";
    return 0;

}