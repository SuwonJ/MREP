#include<iostream>
#include<vector>
using namespace std;


vector<int> vec;
int n,visit[9];

void dfs(){
	if(vec.size()==n){
		int i=0;
		for(i=0;i<vec.size();i++){
			cout<<vec[i];
		}
		cout<<"\n";
		return;
	}
	

	for(int i=1;i<=n;i++){
		if(visit[i]==0){
			visit[i]=1;
			vec.push_back(i);
			dfs();
			visit[i]=0;
			vec.pop_back();
		}
	}
}

int main(void) {
	cin>>n;
	dfs();
	return 0;

}

