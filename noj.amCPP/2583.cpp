#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct sqrr {
	int x;
	int y;
};
queue<struct sqrr> q;
int ppr[101][101] = {};
int re, m;
int cntaa[625];

void bfs();
int wid, higt, tmpx, tmpy, cnt;

int main() {
	struct sqrr sqrrr = {};
	int i, j, k, s1=0, s2=0, e1=0, e2=0;
	cin >> higt >> wid >> re;
	for (k = 0; k < re; k++) {
		cin >> s1 >> s2 >> e1 >> e2;
		for (j = s1; j < e2 - s1;j++) {
			cout <<"["<< i<<"]["<<j<<"]"<<endl;
			for (i = s2; i < e1 - s2; i++) {
				ppr[j][i] = 1;
				cout << "high";
			}
		}
	}
	for (j = s1; j < e1 - s1; j++) {
		for (i = s2; i < e2 - s2; i++) {
			
			cout <<ppr[j][i] ;
		}
	}
	for (i = 0; i < tmpy; i++) {
		for (j = 0; j < tmpx; j++) {
			if (ppr[i][j] == '1') {
				q.push({ j, i });
				ppr[i][j] = '0';
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
	struct sqrr sqrrr;
	while (q.empty() == 0) {
		sqrrr = q.front();
		q.pop();
		cnta+=1;
		for (int i = 0; i < 4; i++) {
			int lntx = sqrrr.x + dx[i];
			int lnty = sqrrr.y + dy[i];
			if (lntx < 0 || lnty < 0|| lntx >=tmpx|| lnty >=tmpy) {
				//cout << "continue";
				continue;
			}
			if (ppr[lnty][lntx] == '1') {
				q.push({ lntx, lnty });
				ppr[lnty][lntx] = '0';
			}
		}
		
	}
	cntaa[cnt] = cnta;
	
}
