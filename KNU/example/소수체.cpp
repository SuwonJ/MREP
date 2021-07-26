#include<iostream>
#include<cstring>

using namespace std;

bool* Sieve(int N) {
	bool* prime = new bool[N+1];
	memset(prime, true, sizeof(bool) * (N+1));

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

int main() {
	
	cout << "정수 N(>=2)을 입력하세요: ";
	int N;
	cin >> N;

	bool* prime = Sieve(N);
	for (int i = 2; i <= N; i++){
        if (prime[i]){
            cout << i << " ";
        }
    }
		
    cout<<"\n";
	return 0;
}   