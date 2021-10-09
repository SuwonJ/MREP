#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int nodenum = 0;
int parents[10001];

struct Vertex {
    int start;
    int end;
    int cost;

    Vertex(int s, int e, int c) {
        start = s;
        end = e;
        cost = c;
    }
};

bool compare(const Vertex& v1, const Vertex& v2) {
    return v1.cost < v2.cost;
}

int getParent(int n) {
    if (parents[n] == n) {
        return n;
    }
    else {
        return parents[n] = getParent(parents[n]);
    }
}

void unionParent(int a, int b) {
    int aParent = getParent(a);
    int bParent = getParent(b);

    if (aParent < bParent) {
        parents[bParent] = aParent;
    }
    else{
        parents[aParent] = bParent;
    }
}

int checkParent(int a, int b) {
    if (getParent(a) == getParent(b)) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(void) {
    int E, tmpa, tmpb, tmpc;
    long long sum = 0;
    cin >> nodenum >> E;
    for (int i = 1; i <= nodenum; i++) {
        parents[i] = i;
    }
    vector<Vertex> Vtx;
    for (int i = 0; i < E; i++) {
        cin >> tmpa >> tmpb >> tmpc;
        Vtx.push_back(Vertex(tmpa, tmpb, tmpc));
    }
    sort(Vtx.begin(), Vtx.end(), compare);

    for (int i = 0; i < Vtx.size(); i++) {
        if (!checkParent(Vtx[i].start, Vtx[i].end)) {
            sum+=Vtx[i].cost;
            unionParent(Vtx[i].start, Vtx[i].end);
        }
    }
    cout << sum;
    
    return 0;
}


