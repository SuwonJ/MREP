#include<iostream>

using namespace std;
int cnt=0;

int gcdA(int a, int b) {
    cnt++;
	cout << "gcd(" << a << "," << b << ")" << endl;
	if (a == b) return a;	// if a==b, then gcd(a,b) is a (or b)
	if (a > b) return gcdA(a - b, b);
	else return gcdA(a, b - a);
}

int gcdB(int a, int b) {
    cnt++;
	cout << "gcd(" << a << "," << b << ")" << endl;
    if(a==0) return b;
    else if(b==0)return a;
    if(a>b) return gcdB(a%b, b);
    else return gcdB(a,b%a);
}

int gcdC(int a, int b) {
   int c;
   while(b!=0){
       cnt++;
       if(a>b){
           c=b;
           b=a%b;
           a=c;
       }
       else{
           b=b%a;
       }
   }
   return a;
}

int relPrime(int a, int b) {
   int c;
   while(b!=0){
       cnt++;
       if(a>b){
           c=b;
           b=a%b;
           a=c;
       }
       else{
           b=b%a;
       }
   }
   if(a==1){
       cout<<"true \n";
       return 0;
   } 
   else{
       cout<<"false \n"; return 0;
   } 
}

int main() {	
	int A, B;
	cout << "두 정수를 입력하세요 (예: 15 18): ";
	cin >> A >> B;
    relPrime(A,B); //서로소
	//cout << "최대공약수: " << gcdC(A, B) << endl;
    //cout<<"함수 "<<cnt<<"번 실행"<<endl;
}