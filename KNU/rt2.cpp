#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>

using namespace std;
int cnta;
vector<int> primeFactorization(int n) {
	vector<int> primeFactors;

	while (n % 2 == 0) {
		primeFactors.push_back(2);
		n /= 2;
        
	}
	for (int i = 3; i * i <= n; i += 2) {
		cout << "divide " << n << " by " << i << endl;
		while (n % i == 0) {
			primeFactors.push_back(i);
            
			    
		}
	}

	if (n > 2){
        primeFactors.push_back(n);
    }
		

	return primeFactors;
}
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
	vector<int> primeFactors = primeFactorization(arr[nm]);
	for (int i = 0; i < primeFactors.size(); i++){
		if(i!=primeFactors.size()-1){
			cout << primeFactors.at(i)<<"*";
		}
		else{
		cout << primeFactors.at(i);
		}
	}
		
	

	return 0;
}