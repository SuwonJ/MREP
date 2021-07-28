#include <iostream>
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

int main() {
	int N;
	cout << "소인수분해할 수를 입력하세요: ";
	cin >> N;

	vector<int> primeFactors = primeFactorization(N);
	for (int i = 0; i < primeFactors.size(); i++)
		cout << primeFactors.at(i) << endl;
}