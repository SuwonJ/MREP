#include<iostream>
#include<cstring>	// for memset() in g++

using namespace std;

/*
* find all primes in 2~N
* and return int[] of these primes
*/
int numPrimes = 0;
bool* prime;
int* Sieve(int N) 
{
	// if i is prime, then prime[i] = true
	// otherwise, prime[i] = false
	prime = new bool[N + 1];
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

	// 2부터 시작하는 연속된 소수의 합을 구해 sum 배열에 저장
	int* sum = new int[numPrimes];
	sum[0] = primes[0];
	for (int i = 1; i < numPrimes; i++)
		sum[i] = sum[i - 1] + primes[i];

	/*
	* 주석 (1)~(3) 아래에 코드를 작성합니다.	 
	*/
	int j=0;
	int max=0;
	for (int i = 0; i < T; i++) {
		max=0;j=0;
		// (1) sum[] 배열에서 N[i]보다 작은 가장 큰 값의 index 구하기3
		int rightBorderIndex = BinarySearch(sum, 0, numPrimes - 1, N[i] - 1);


		// (2) 앞에서 구한 index에서부터 합이 소수인 지점까지 왼쪽으로 이동
		//     값 k가 소수임을 확인하기 위해서는 prime[k]==true 임을 활용
		
		for(j=rightBorderIndex;j>0;j--){
			if(prime[sum[j]]==true){
				//if(max<(rightBorderIndex-j)){
				//	max=rightBorderIndex-j;
					break;
				//}
			}
			
		}
		// (3) 결과 출력
		 cout << sum[j] << " " << (j+1) << endl;

	}

	return 0;
}