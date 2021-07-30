#include<iostream>
#include<vector>
#include<iomanip>	// for setprecision

using namespace std;

int main() {
	// K, N, I 값을 차례로 입력받음
	int K, N, I;
	cin >> K >> N >> I;

	vector<double> prob;			// P[i] (state i에 도달할 확률) 차례대로 저장하는 리스트
	vector<vector<double>> probTransition;	// Ptransition[i][j] (state i --> j로 이동할 확률) 저장하는 리스트

	// P[i]의 초깃값 지정
	prob.push_back(1);				// P[0] = 1
	for (int i = 1; i <= K-1; i++)	// P[i] = 0 (for i = 1 ~ K-1)
		prob.push_back(0);

	// 이동 확률 Ptransition[i][j] 지정
	for (int i = 0; i < K; i++) {
		vector<double> probRow;		// Ptransition[i] (2차원 리스트의 i번째 행)
		for (int j = 0; j < K; j++)	// Ptransition[i][j]=0으로 초기화
			probRow.push_back(0);
		
		// Ptransition[i][j] 값 지정
		// probRow.at(j) = (double) 1/5 와 같이 값을 할당할 수 있으며
		// probRow.at(j) += (double) 1/5 과 같이 기존 값에 더할 수도 있음		
		for (int j = 1; j <= N; j++) {
			int index = (i + j) % K;
			probRow.at(index) += (double)1 / N;
		}		

		probTransition.push_back(probRow);	// 준비한 i번째 행을 Ptransition에 추가

		// 지정한 이동 확률 출력
		/*
		for (int j = 0; j < K; j++)
			cout << probRow.at(j) << " ";
		cout << endl;
		*/
	}

	// I번의 Iteration 돌며 확률 계산
	for (int i = 0; i < I; i++) {
		// probTmp는 이번 iteration에서 계산할 P[i]를 임시로 저장할 리스트이며
		// 지난 iteration까지 계산한 P[i]는 prob에 저장되어 있음
		vector<double> probTmp;			
		for (int j = 0; j < K; j++)		// 모든 state에 대한 확률을 0으로 초기화
			probTmp.push_back(0);

		// 지난 iteration까지 계산한 P[i](prob에 저장되어 있음)와 
		// 이동확률 Ptransition[i][j]을 사용해
		// 이번 iteration에서의 P[i]를 계산해 probTmp에 저장
		for(int from = 0; from < K; from++) {				
			for (int to = 0; to < K; to++) {					
				probTmp.at(to) += prob.at(from) * probTransition.at(from).at(to);					
			}
		}

		// probTmp에 저장해둔 이번 iteration에서 계산한 P[i]를
		// prob에 저장해서 다음 iteration에서 사용할 수 있도록 함
		prob = probTmp;
	}

	// 결과 출력
	for (int i = 0; i < K; i++)
		cout << fixed << setprecision(5) << prob.at(i) << endl;

	return 0;
}