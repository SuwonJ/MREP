#include<iostream>
using namespace std;

int n, m, v,visit[1001];
int vtx[1001][1001];

void dfs(int tmpV);

int main(void) {
	cin >> n>> m>>v;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vtx[a][b] = 1;
		
	}
	dfs(v);
	return 0;

}

void dfs(int tmpV) {
	visit[tmpV] = 1;
	cout << tmpV;
	for (int i = 0; i <= n; i++) {
		if (visit[i] == 0 && vtx[tmpV][i] == 1) {
			dfs(i);
		}
	}
}