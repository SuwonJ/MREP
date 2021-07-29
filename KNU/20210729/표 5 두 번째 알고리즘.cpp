#include<iostream>
#include<chrono>

using namespace std;

/*
* 프로그램 내 특정 구간의 수행 시간 측정
* 측정하고자 하는 구간 (i) 전과 (ii) 후에 이 함수 호출
*/
bool firstMeasure = true;
chrono::high_resolution_clock::time_point startTime, endTime;
void measureTime(string msg)
{
	if (firstMeasure)
	{
		startTime = chrono::high_resolution_clock::now();
		firstMeasure = false;
	}
	else
	{
		endTime = chrono::high_resolution_clock::now();
		chrono::duration<double, milli> time_span = endTime - startTime;
		cout << msg << " " << time_span.count() << " ms\n";
		startTime = endTime;
	}

	return;
}

long phiUsingPrimeFactorization(long n) {
	long phi = n;

	if (n % 2 == 0) {	// 2가 소인수인지 확인
		phi = phi / 2 * (2 - 1);
		do { n /= 2; } while (n % 2 == 0);
	}

	// 그 외 ~sqrt(n) 까지 홀수가 소인수인지 확인
	for (long i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			phi = phi / i * (i - 1);
			do { n /= i; } while (n % i == 0);
		}		
	}

	if (n > 2)	// 남은 수도 소인수
		phi = phi / n * (n - 1);		

	return phi;
}

int main()
{
	cout << "정수 N을 입력하세요: ";
	long N;
	cin >> N;

	measureTime("");

	double maxNPhi = 0;
	long maxN = 0;
	for (long n = 2; n <= N; n++) {	// 2~N 범위의 각 n에 대해 n/phi(n) 계산		
		long phi = phiUsingPrimeFactorization(n);	// phi(n) 계산				
		double nPhi = (double)n / phi;  // n/phi(n) 계산

		if (nPhi > maxNPhi) {			// n/phi(n)이 max인 경우 기록
			maxNPhi = nPhi;
			maxN = n;
			//cout << "n = " << maxN << " 일 때 phi(n) " << phi << " 가짐" << endl;
		}
	}

	measureTime("");

	cout << "n = " << maxN << " 일 때 n/phi(n)이 최댓값 " << maxNPhi << " 가짐" << endl;

	return 0;
}