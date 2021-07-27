#include<iostream>
#include<cstring>	// for memset() in g++

using namespace std;

/*
* find all primes in 2~N
* and return int[] of these primes
*/
int numPrimes = 0;
int* Sieve(int N) 
{
	// if i is prime, then prime[i] = true
	// otherwise, prime[i] = false
	bool* prime = new bool[N + 1];
	memset(prime, true, sizeof(bool) * (N + 1));

	for (int i = 2; i * i <= N; i++) 
	{		
		if (prime[i]) 
		{
			for (int j = i * i; j <= N; j += i) 
			{
				prime[j] = false;
			}
		}
	}

	// build a list of prime numbers <= N
	numPrimes = 0;
	for (int i = 2; i <= N; i++)
		if (prime[i]) numPrimes++;
	int* primes = new int[numPrimes];
	for (int i = 2, j = 0; i <= N; i++)
		if (prime[i]) primes[j++] = i;

	return primes;
}

// list 배열에서 I와 같거나 작은 가장 큰 값의 index 찾아 반환
int BinarySearch(int* list, int from, int to, int I) 
{
	if (from > to) return to; // I does not exist in list
	
	int mid = (from + to) / 2;
	if (list[mid] == I) return mid;	
	else if (list[mid] < I)
		return BinarySearch(list, mid + 1, to, I);
	else
		return BinarySearch(list, from, mid - 1, I);
}

int main() 
{
	// 테스트 케이스 수 T 입력 받음
	int T;
	cin >> T;

	// T개 만큼의 N을 배열로 입력받고, 이들의 최댓값을 maxN에 저장
	int* N = new int[T];
	int maxN = 0;
	for (int i = 0; i < T; i++) 
	{
		cin >> N[i];
		if (maxN < N[i]) maxN = N[i];
	}
	
	// N값 중 가장 큰 값(maxN) 이하의 소수를 모두 찾아 배열 primes[]에 저장
	int* primes = Sieve(maxN);

	/*
	* 여기서부터 코드를 수정하세요.
	*/
	// 배열 primes[]에 저장된 값 모두 출력
	for (int i = 0; i < numPrimes; i++)
		cout << primes[i] << " ";
	cout << endl;

	// N[0]보다 작은 큰 소수 출력
	int index = BinarySearch(primes, 0, numPrimes - 1, N[0] - 1);
	cout << primes[index] << endl;
	
	return 0;
}