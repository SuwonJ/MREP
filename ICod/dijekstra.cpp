#include<iostream>
#define INTS 2147483647
using namespace std;
#include <queue>
#include<vector>

int number = 6;

vector<pair<int, int>> v[7];

int minD[7] = { INTS,INTS,INTS,INTS,INTS,INTS,INTS };

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
    //간선정보 입력
    v[1].push_back(make_pair(2, 2));

    v[1].push_back(make_pair(3, 5));

    v[1].push_back(make_pair(4, 1));



    v[2].push_back(make_pair(1, 2));

    v[2].push_back(make_pair(3, 3));

    v[2].push_back(make_pair(4, 2));



    v[3].push_back(make_pair(1, 5));

    v[3].push_back(make_pair(2, 3));

    v[3].push_back(make_pair(4, 3));

    v[3].push_back(make_pair(5, 1));

    v[3].push_back(make_pair(6, 5));



    v[4].push_back(make_pair(1, 1));

    v[4].push_back(make_pair(2, 2));

    v[4].push_back(make_pair(3, 3));

    v[4].push_back(make_pair(5, 1));



    v[5].push_back(make_pair(3, 1));

    v[5].push_back(make_pair(4, 1));

    v[5].push_back(make_pair(6, 2));



    v[6].push_back(make_pair(3, 5));

    v[6].push_back(make_pair(5, 2));

    dijkstra(1);
    cout << minD[6] << "\n";
    return 0;

}