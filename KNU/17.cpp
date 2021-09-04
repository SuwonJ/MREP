#include<iostream>
#include<vector>
#include<algorithm>	// for min, max, sort
#include<cmath>		// for atan2

using namespace std;

const double pi = 3.14159265358979323846;	// 원주율 상수 정의

struct AnglePair {
	double from, to;
	AnglePair(double from, double to) {
		this->from = from;
		this->to = to;
	}
};

bool intersect(AnglePair r1, AnglePair r2) {
	double fromMax = max(r1.from, r2.from);
	double toMin = min(r1.to, r2.to);
	return fromMax < toMin;
}

bool intersectList(vector<AnglePair> list1, vector<AnglePair> list2) {
	for (int i = 0; i < list1.size(); i++) {
		for (int j = 0; j < list2.size(); j++) {
			if (intersect(list1[i], list2[j])) return true;
		}
	}
	return false;
}

AnglePair merge(AnglePair r1, AnglePair r2) {
	double fromMin = min(r1.from, r2.from);
	double toMax = max(r1.to, r2.to);
	return AnglePair(fromMin, toMax);
}

/*
* AnglePair의 리스트에 대한 정렬 기준을 정하는 함수 
* r1이 r2보다 작을 때 true를 return하도록 함
*/
bool compareAnglePairs(AnglePair r1, AnglePair r2) {
	if (r1.from < r2.from) return true;
	else if (r1.from > r2.from) return false;
	else {
		if (r1.to < r2.to) return true;
		else return false;
	}
}

vector<AnglePair> mergeList(vector<AnglePair> list1, vector<AnglePair> list2) {
	vector<AnglePair> all;
	all.insert(all.end(), list1.begin(), list1.end());	// add all elements of list1
	all.insert(all.end(), list2.begin(), list2.end());	// add all elements of list2
	sort(all.begin(), all.end(), compareAnglePairs);

	vector<AnglePair> merged;
	AnglePair prev = all[0];
	for (int i = 1; i < all.size(); i++) {
		AnglePair next = all[i];
		if (intersect(prev, next)) {
			prev = merge(prev, next);
		}
		else {
			merged.push_back(prev);
			prev = next;
		}
	}
	merged.push_back(prev);

	return merged;
}

/*
* p0와 p1이 이루는 각도 및 p0와 p2가 이루는 각도를 AnglePair로 만들어 반환
* 두 각도의 차이가 pi(180도) 이상이라면 2개의 range로 나누어 반환 
*/
vector<AnglePair> createAnglePairList(double p0x, double p0y,
	double p1x, double p1y, double p2x, double p2y) {
	double angle1 = atan2(p1y - p0y, p1x - p0x);
	double angle2 = atan2(p2y - p0y, p2x - p0x);
	double angleMin = min(angle1, angle2);
	double angleMax = max(angle1, angle2);

	vector<AnglePair> list;
	if (angleMax - angleMin < pi) {
		list.push_back(AnglePair(angleMin, angleMax));
	}
	else {
		list.push_back(AnglePair(angleMax, pi));
		list.push_back(AnglePair(-pi, angleMin));
	}

	return list;
}

int main() {
	/*1
	AnglePair r1 = AnglePair(-pi, pi);	
	AnglePair r2 = AnglePair(-pi/2,pi/2);
	AnglePair r3 = AnglePair(-pi/4,pi/4*3);

	cout << r1.from << "~" << r1.to << endl;	
	cout << r2.from << "~" << r2.to << endl;	
	cout << r3.from << "~" << r3.to << endl;	
	*/
	/*2
	AnglePair r1 = AnglePair(-pi, -pi/4);	
	AnglePair r2 = AnglePair(-pi/2,pi/2);
	AnglePair r3 = AnglePair(0,pi/4);
	AnglePair r4 = AnglePair(pi/4*3,pi);

	cout<<intersect(r1,r2)<<endl;
	cout<<intersect(r1,r3)<<endl;
	cout<<intersect(r2,r3)<<endl;
	cout<<intersect(r2,r4)<<endl;
	*/
	AnglePair r1 = AnglePair(-pi, -pi/4);	
	AnglePair r2 = AnglePair(-pi/2,pi/2);
	AnglePair r3 = AnglePair(0,pi/4);
	AnglePair r4 = AnglePair(pi/4*3,pi);

	vector<AnglePair> l1;
	l1.push_back(r1);
	l1.push_back(r3);

	vector<AnglePair> l2;
	l2.push_back(r2);
	l2.push_back(r4);
	
	vector<AnglePair> l3;
	l3.push_back(r4);

	cout<<intersectList(l1,l2)<<endl;
	cout<<intersectList(l1,l3)<<endl;
	cout<<intersectList(l2,l3)<<endl;

	return 0;
}