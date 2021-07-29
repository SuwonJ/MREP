#include<iostream>
#include<vector>	// for vector
#include<cstring>	// for memset

using namespace std;

/*
* 소수체 방법 사용해
* 2~N 사이의 모든 소수를 찾아 int형 vector로 반환
*/
vector<int> Sieve(int N) 
{
	bool* prime = new bool[N + 1];
	memset(prime, true, sizeof(bool) * (N + 1));

	vector<int> primes;

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

	for (int i = 2; i <= N; i++)
		if (prime[i]) primes.push_back(i);

	return primes;
}

/*
* 이진탐색 방법 사용해
* int형 vector list에서 찾고자 하는 값 I의 index 반환
* I가 없을 경우 I 바로 전 값의 index 반환
*/
int BinarySearch(vector<int> list, int from, int to, int I) 
{
	if (from > to) return to; // I가 리스트에 없는 경우 I 이전 값의 index 반환

	int mid = (from + to) / 2;
	if (list.at(mid) == I) return mid;
	else if (list.at(mid) < I)
		return BinarySearch(list, mid + 1, to, I);
	else
		return BinarySearch(list, from, mid - 1, I);
}

int main() 
{
	int T;
	cin >> T;

	// T개 만큼의 N 입력 받아 int형 vector에 저장
	vector<int> N;
	int maxN = 0;
	for (int i = 0; i < T; i++) 
	{
		int input;
		cin >> input;
		N.push_back(input);
		if (input > maxN) maxN = input;
	}	

	// 입력받은 N 중 최댓값보다 작거나 같은 소수 모두 구하기
	vector<int> primes = Sieve(maxN);

	// 각 N에 대해 phi(n)/n을 최대로 하는 n값 찾아 출력
	for (int i = 0; i < T; i++) 
	{
		// 입력받은 N을 저장한 리스트에서 i 위치 값을 읽을 때는 N.at(i) 사용		
		// 마찬가지로 소수 리스트 primes도 primes.at(index) 사용해 읽을 수 있으며
		// 리스트에 속한 원소 수는 primes.size()를 호출해 얻을 수 있음
		/*
		* 여기서부터 코드를 작성하세요.
		*/
		
		/*
		* 여기까지 코드를 작성합니다.
		*/
	}

	return 0;
}