#include<iostream>
#include<math.h>

using namespace std;

void findDivisors1(int n){
	for (int i = 1; i <= n; i++){
		if (n % i == 0){
			if(i!=1){
					cout << i <<"*"<< i<< "\n";
			}
			else{
				cout << i<< "\n";
			}
		}
	}
	cout << "\n";
}

void findDivisors2(int n){
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			//cout <<n<<"*"<< i << " ";
			int tmp = n / i;
			if (tmp != i){
				if(i!=1){
					cout << tmp <<"*"<< i<< "\n";
				}
				else{
					cout << tmp<< "\n";
				}
			}
		}
	}
	cout << "\n";
}

void findDivisors3(int n)
{
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			//cout << i << " ";
			int tmp = n / i;
			if (tmp != i){
				if(i!=1){
					cout << tmp <<"*"<< i<< "\n";
				}
				else{
					cout << tmp<< "\n";
				}
			}
				
		}
	}
	cout << "\n";
}

int main() 
{
	int n;
	cin >> n;

	findDivisors3(n);

	return 0;
}