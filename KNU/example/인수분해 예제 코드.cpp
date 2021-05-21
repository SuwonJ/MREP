#include<iostream>

using namespace std;

void printSequence(int depth, int sequence[])
{	
	for (int i = 0; i < depth; i++)
	{
		cout << sequence[i];
		if (i < depth-1) cout << "*";
	}
	cout << "\n";
}

/*
* n is an integer >= 1* 
*/
void findAllFactorization(int n, int depth, int sequence[], int factorMin)
{
	if (n == 1)
		printSequence(depth, sequence);
	else
	{
		for (int i = factorMin; i <= n; i++)
		{
			if (n % i == 0)
			{				
				sequence[depth] = i;
				findAllFactorization(n / i, depth + 1, sequence, i);
			}
		}
	}
}

int main() 
{
	int n;
	cin >> n;

	findAllFactorization(n, 0, new int[100], 2);

	return 0;
}