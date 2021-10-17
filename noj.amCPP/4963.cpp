#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct island {
	int x;
	int y;
};
queue<struct island> q;
int sea[51][51] = {};
int re, m;

void bfs();
int wid, higt, tmpx, tmpy;
int main() {
	struct island lnd = {};
	int ld, i, j, cnt;
	while (1) {
		cnt = 0; ld = 0; tmpx = 0; tmpy = 0;
		for (j = 0; j < 51; j++) {
			for (i = 0; i < 51; i++) {
				sea[j][i] = 0;
			}
		}
		
		cin >> tmpx >> tmpy;
		if (tmpx == 0 && tmpy == 0) {
			break;
		}
	
	
	for (i = 0; i < tmpy; i++) {
		for (j = 0; j < tmpx; j++) {
			cin >> sea[j][i];
		}
	}
	for (i = 0; i < tmpy; i++) {
		for (j = 0; j < tmpx; j++) {
			if (sea[i][j] == 1) {
				lnd.x = j;
				lnd.y = i;
				q.push({ j, i });
				sea[i][j] = 0;
				bfs();
				cnt++;
			}
		}
	}
	cout <<cnt<<endl;
	}
	
	return 0;
}
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
void bfs() {
	struct island lnd;
	while (q.empty() == 0) {
		lnd = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int lntx = lnd.x + dx[i];
			int lnty = lnd.y + dy[i];
			if (lntx < 0 || lnty < 0|| lntx >=tmpx|| lnty >=tmpy) {
				continue;
			}
			if (sea[lnty][lntx] == 1) {
				q.push({ lntx, lnty });
				sea[lnty][lntx] = 0;
			}
		}
	}
}
                  
