#include<iostream>

using namespace std;

int main() {
	/*
	* receive input n
	* initialize array s[] that stores sum of factors
	*/
	int n;
	cin >> n;

	int* s = new int[n + 1];
	for (int a = 0; a <= n; a++)
		s[a] = 0;

	/*
	* find all factors for a=2~N and add to s[a]
	*/	
	for (int n1 = 2; n1 <= n/2; n1+=2)	// increase n1 by 2, so that n1 remains even
	{
		for (int n2 = 2; n1 * n2 <= n; n2++)
		{
			s[n1 * n2] += n1;			
		}
	}

	for (int a=2; a<=n; a++)
		cout << "s[" << a << "] = " << s[a] << "\n";

	return 0;
}  