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

int main() 
{
	// 100 이하의 소수를 모두 찾아 int형 리스트 primes에 저장
	vector<int> primes = Sieve(100);

	// T개 만큼의 N을 입력받아 답을 출력
	int T,maxP;
	unsigned long long N;
	cin >> T;
	for (int i = 0; i < T; i++) 
	{
		cin >> N;				
		unsigned long long nMax = 1;	// 이 변수에 n/phi(n)이 최대가 되는 n 값을 저장

		// nMax에 가장 작은 소수부터 차례로 곱해가되, N보다 커지기 직전까지 곱함
		// 소수 리스트 primes의 index 위치 값을 읽을 때는 primes.at(index) 사용		
		// 예를 들어 가장 작은 소수인 2는 primes.at(0)로 읽을 수 있으며
		// 그 다음 소수인 3은 primes.at(1)로 읽을 수 있음
		/*
		* 여기서부터 코드를 작성하세요
		*/
	unsigned long long tmp=0;
			for(int i=0;i<N;i++){
				nMax*=primes.at(i);
				if(nMax>N){
					nMax=tmp;
					break;
					
				}
				tmp=nMax;
			}
		/*
		* 여기까지 코드를 작성합니다.
		*/

		// n/phi(n)이 최대가 되는 n 출력
		cout << nMax << endl;
	}	

	return 0;
}