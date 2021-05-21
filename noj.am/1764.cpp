#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int comp(const void* p1, const void* p2) {
	return strcmp((char*)p1, (char*)p2);
}
char sv[1000000][20] = {};
int n, m;


int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n+m; i++) {
		cin >> sv[i];
	}
	qsort(sv, m + n, sizeof(char) * 20, comp);
	//cout << "=====================" << endl;
	for (int i = 0; i < m + n; i++) {
		/*cout << sv[i]<<endl;*/
	}

    int cnt=0;
	for (int i = 0; i < m+n-1; i++) {
		if (strcmp(sv[i] , sv[i + 1])==0) cnt++;
	}
    cout<<cnt<<endl;
    for (int i = 0; i < m+n-1; i++) {
		if (strcmp(sv[i] , sv[i + 1])==0) cout<<sv[i]<<endl;
	}
	return 0;
}