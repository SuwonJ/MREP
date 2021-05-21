#include <iostream>
using namespace std;
int main(void) {
	int r = 0, max = 0, a, b, c, d, tr = 0, trd = 0;
	
	cin >> r;
	for (int i = 0; i < r; i++) {
		int dd[7] = {};
		cin >> a >> b >> c >> d;
		dd[a]++; dd[b]++; dd[c]++; dd[d]++;
		tr = 0;
		if (b > a) a = b;
		if (c > a) a = c;
		if (d > a) a = d;
		a *= 100;
		for (int j = 1; j <= 6; j++) {
			if (dd[j] == 4) {
				a = 50000 + 5000 * j;
				break;
			}
			if (dd[j] == 3) {
				a = 10000 + 1000 * j;
				break;
			}
			if (dd[j] == 2) {
				a = 1000 + 100 * j;
				if (tr == 1) {
					a = 2000 + 500 * (j + trd);
					break;
				}
				trd = j;
				tr = 1;
			}

		}
		if (max < a) max = a;
	}
	cout << max;
}
