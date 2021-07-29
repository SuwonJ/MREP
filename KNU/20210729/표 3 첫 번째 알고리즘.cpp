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

/*
* 최대공약수(greatest common divisor)를 계산하는 함수
*/
long gcd(long a, long b) {	
	long c;
	while (b != 0) {
		if (a > b) { c = b; b = a % b; a = c; } // keep a>b, so that b becomes 0
		else { b = b % a; }
	}
	return a;
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
		long phi = 0;
		for (long i = 1; i < n; i++)	// phi(n) 계산
			if (gcd(i, n) == 1) phi++;
		double nPhi = (double)n / phi;  // n/phi(n) 계산

		if (nPhi > maxNPhi) {			// n/phi(n)이 max인 경우 기록
			maxNPhi = nPhi;
			maxN = n;
		}
	}

	measureTime("");

	cout << "n = " << maxN << " 일 때 n/phi(n)이 최댓값 " << maxNPhi << " 가짐" << endl;
	
	return 0;
}