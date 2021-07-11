#include<iostream>
#include<vector>
using namespace std;


vector<int> vec;
int n,visit[9];

void dfs(int r){
	if(vec.size()==n){
		int i=0;
		for(i=0;i<vec.size();i++){
			cout<<vec[i];
		}
	}
	cout<<"\n";

	for(int i=0;i<n;i++){
		if(visit[i]==0){
			visit[i]=1;
			
		}
	}
}

int main(void) {
	cin>>n;
	return 0;

}

