#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
queue<int> q;
int list[1001][1001] = {};
int dupl[1001] = {};
int re, m;

void bfs();

int main() {
	int i, ta, tb, j,   cnt = 0;
	cin >> m >> re;
	for (i = 0; i < re; i++) {
		cin >> ta >> tb;
		list[ta][tb] = 1;
		list[tb][ta] = 1;
	}
	for (j = 1; j < m + 1; j++) {
		if (dupl[j] == 0) {
			q.push(j);
			dupl[j] = 1;
			bfs();
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}

void bfs() {
	while (q.empty() == 0) {
		int temp = q.front();
		q.pop();
		for (int i = 1; i < m + 1; i++) {
			if (list[temp][i]==1 && (dupl[i] == 0)) {
				q.push(i);
				dupl[i] = 1;
			}
		}
	}
}
