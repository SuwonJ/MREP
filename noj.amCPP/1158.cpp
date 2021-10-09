#include<iostream>
#include<queue>
using namespace std;
queue<int> q;

int main(){
    int N, K, i,j;
	cin >> N >> K;
	cout << "<";
	for (i = 0; i < N; i++) {
		q.push(i+1);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < K - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		if (q.size() == 1) {
			cout << q.front() << ">";
		}
		else {
			cout << q.front() << ", ";
		}
		q.pop();
	}


	return 0;
}

