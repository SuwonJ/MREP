#include<iostream>
#include<algorithm>	// for min()
#include<cmath>

using namespace std;

/*
* a와 b의 최대공약수(gcd, greatest common divisor)를 구해 반환하는 함수
*/
int gcd(int a, int b) {
	int tmp;
	while (b != 0) {
		if (a > b) {
			tmp = b; b = a % b; a = tmp;
		}
		else {
			b = b % a;
		}
	}
	return a;
}
int sq(int a){
    return a*a;
}
int main() {
	int N, x1, y1,AW=0,lft,rgt;;;

	cin >> N >> x1 >> y1;
    AW+=3*N*N;


	/*
	* 여기서부터 코드 작성:
	*   (1) A 왼쪽에 있는 점의 수 계산
	*	(2) A 오른쪽에 있는 점의 수 계산
	*	(3) (1)~(2)에서 계산한 값 출력
	* 
	* min 함수 사용법: min(a,b) 호출하면 a와 b 중 더 작은 값 반환
	*		#include<algorithm> 하였으므로 별도로 정의할 필요 없이 바로 사용 가능
	*/
    int cf=floor((sq(x1)+sq(y1))/y1);

    cout<<((min(N,cf))-y1)/(x1/gcd(x1, y1))<<" ";

    int df=floor((sq(x1)+sq(y1))/x1);

    cout<<((min(N,df))-x1)/(y1/gcd(x1, y1))<<"\n";
    //lft=(min(N,floor((sq(x1)+sq(y1))/y1))-y1)/(x1/gcd(x1, y1));
    //rgt=(min(N,floor((sq(x1)+sq(y1))/x1))-x1)/(y1/gcd(x1, y1));
	/*
	* 여기까지 코드 작성
	*/

	return 0;
}