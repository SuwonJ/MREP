#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct aprt {
	int x;
	int y;
};
queue<struct aprt> q;
char map[26][26] = {};
int re, m;
int cntaa[625];

void bfs();
int wid, higt, tmpxy, cnt;

int main() {
	struct aprt apt = {};
	int ld, i, j,tmp,min,itmp;
		cnt = 0; ld = 0; tmpxy = 0;
		cin >> tmpxy;
		for (i = 0; i < tmpxy; i++) {
			for (j = 0; j < tmpxy; j++) {
				cin >> map[i][j];
			}
		}
		
		for (i = 0; i < tmpxy; i++) {
			for (j = 0; j < tmpxy; j++) {
				if (map[i][j] == '1') {
					q.push({ j, i });
					map[i][j] = '0';
					bfs();
					cnt++;
				}
			}
		}
		cout <<cnt<<endl;
		sort(cntaa, cntaa + cnt);
		for (i = 0; i < cnt; i++) {
			cout << cntaa[i]<<endl;
		}
		
	return 0;
}
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void bfs() {
	int cnta=0;
	struct aprt apt;
	while (q.empty() == 0) {
		apt = q.front();
		q.pop();
		cnta+=1;
		for (int i = 0; i < 4; i++) {
			int lntx = apt.x + dx[i];
			int lnty = apt.y + dy[i];
			if (lntx < 0 || lnty < 0|| lntx >=tmpxy|| lnty >=tmpxy) {
				//cout << "continue";
				continue;
			}
			if (map[lnty][lntx] == '1') {
				q.push({ lntx, lnty });
				map[lnty][lntx] = '0';
			}
		}
		
	}
	cntaa[cnt] = cnta;
	
}
