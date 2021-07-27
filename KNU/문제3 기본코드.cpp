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

	// 연속된 소수의 합을 구해 sums 배열에 저장	
	int* sums = new int[numPrimes];
	sums[0] = primes[0];
	for (int i = 1; i < numPrimes; i++)
		sums[i] = sums[i - 1] + primes[i];

	/*
	* 주석 (1)~(2) 아래에 코드를 작성합니다.
	*/
	int leftBorder, rightBorder, maxSum, maxLength, sum;
	for (int i = 0; i < T; i++) 
	{
		leftBorder = 0, maxSum = 0, maxLength = 0;

		// sum[] 배열에서 N[i]보다 작은 가장 큰 값의 index 구하기
		int rightBorder = BinarySearch(sums, 0, numPrimes - 1, N[i] - 1);
		
		// rightBorder --> leftBorder 범위의 값이 소수인지 확인하고
		//		소수이면 maxSum, maxLength 업데이트
		//		값 k가 소수임을 확인하기 위해서는 prime[k]==true 임을 활용
		//		row, col은 각각 현재 검색하는 행, 열을 의미
		for (int row = 0; leftBorder < rightBorder; row++) 
		{
			for (int col = rightBorder; col >= leftBorder; col--) 
			{
				if (row > 0) sum = sums[col] - sums[row - 1];
				else sum = sums[col];
				
				if (prime[sum]) 
				{
					// (1) sum이 소수라면 maxLength, maxSum 조정
					// maxLength = ?;
					// maxSum = ?;					


					break;
				}
			}

			// (2) 다음 행에서 사용할 rightBorder와 leftBorder 값 지정
			// rightBorder = ?;
			// leftBorder = ?;
			

		}

		// 결과 출력
		cout << maxSum << " " << maxLength << endl;
	}

	return 0;
}