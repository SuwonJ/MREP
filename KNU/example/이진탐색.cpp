#include<iostream>
#include<algorithm>
#include<chrono>	// for time()

using namespace std;

int BinarySearch(int* list, int from, int to, int I, int depth) {
	if (from > to) {
		//cout << "found the answer after " << depth << " comparisons" << endl;
		return -1;	// I does not exist in list
	}

	int mid = (from + to) / 2;
	if (list[mid] == I) {
		//cout << "found the answer after " << (depth + 1) << " comparisons" << endl;
		return mid;
	}
	else if (list[mid] < I)
		return BinarySearch(list, mid + 1, to, I, depth+1);
	else
		return BinarySearch(list, from, mid - 1, I, depth+1);
}

int main() {	
	// create an array with random integers between 0~999
	int listLength = 10;
	int* list = new int[listLength];
	srand(time(0));					// seed random number generator
	for (int i = 0; i < listLength; i++) {
		list[i] = rand() % 1000;
	}	

	sort(list, list + listLength);
	for (int i = 0; i < listLength; i++) {		
		cout << list[i] << " ";
	}
	cout << endl;

	while (true) {
		cout << "리스트에서 찾고자 하는 정숫값을 입력하세요 (음수 입력 시 종료): ";
		
		int I;
		cin >> I;
		if (I < 0) break;

		int index = BinarySearch(list, 0, listLength - 1, I, 0);
		cout << "index = " << index << endl;
	}

	return 0;
}