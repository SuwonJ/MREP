#include<iostream>

using namespace std;

int main() {
	int n, p;
	cin >> n;
	cin >> p;

	for (int i = 1;; i++)
	{
		int a = 1;
		for (int j = 1; j <= p; j++) a *= i;	// a = i^p
		if (a > n) break;	// a should stay within 1~N
		cout << a << "\n";
	}

	return 0;
}