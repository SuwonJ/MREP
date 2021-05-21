#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

struct cabbage {
	int x;
	int y;
};
queue<struct cabbage> q;
int field[51][51] = {};
int re, m;

void bfs();
int wid, higt;
int main() {
	int r1,cbg, i, j, tmpx, tmpy, r,cnt;
	cin >> r1;
	
	for (r = 0; r < r1; r++) {
		cnt = 0; cbg = 0; tmpx = 0; tmpy = 0;;
		for (j = 0; j < 51; j++) {
			for (i = 0; i < 51; i++) {
				field[j][i] = 0;
			}
		}
		cin >> wid >> higt >> cbg;
		struct cabbage cwew = {};
		for (i = 0; i < cbg; i++) {
			cin >> tmpx >> tmpy;
			field[tmpy][tmpx] = 1;
		}
		/*for (i = 0; i < higt; i++) {
			for (j = 0; j < wid; j++) {
				cout << field[i][j];

			}
			cout << endl;
		}*/
		for (i = 0; i < higt; i++) {
			for (j = 0; j < wid; j++) {
				if (field[i][j] == 1) {
					cwew.x = j;
					cwew.y = i;
					q.push({ j, i });
					field[i][j] = 0;
					bfs();		
					cnt++;
				}
			}
		}
		cout <<cnt<<endl;
	}
	return 0;
}
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void bfs() {
	struct cabbage cwew;
	while (q.empty() == 0) {
		cwew = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cnewx = cwew.x + dx[i];
			int cnewy = cwew.y + dy[i];
			if (cnewx < 0 || cnewy < 0|| cnewx >=wid|| cnewy >=higt) {
				//cout << "LC (" << cnewx << "," << cnewy << ")" << endl;
				continue;
			}
			//else {
				//cout << "RRT";
				if (field[cnewy][cnewx] == 1) {
					q.push({ cnewx, cnewy });
					field[cnewy][cnewx] = 0;
					/*for (int i = 0; i < higt; i++) {
						for (int j = 0; j < wid; j++) {
							cout << field[i][j];
						}
					}*/
				}
			//}
		}
	}
	
}
