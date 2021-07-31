#include<iostream>
#include<cstring>

using namespace std;
int sib(int N) {
	int i = 0;
	for (i = 2; i < 1000002;i++) {
		if (N % i == 0) {
			break;
		}
	}
	return i;
}
bool* Sieve(int N) {
	bool* prime = new bool[N + 1];
	memset(prime, true, sizeof(bool) * (N + 1));

	for (int i = 2; i * i <= N; i++) {
		//cout << i << endl;
		if (prime[i]) {
			for (int j = i * i; j <= N; j += i) {
				prime[j] = false;
			}
		}
	}

	return prime;
}
int N,arr[1000000],j,nm;
int main() {
cin >> N>>nm;

	bool* prime = Sieve(N);
	j = 0;
	for (int i = 2; i <= N; i++) {
		if (prime[i]) {}
		else {
			j++;
			arr[j] = i;
		}
	}
	cout << arr[nm]<<"=";
	
	

	return 0;
}