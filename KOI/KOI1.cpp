#include <iostream>
using namespace std;

int main(void) {
	int n,arr[100000]={},tmp=0,tmpb=0,tmpc=0,max=0,a=0,b=0,c=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
        /////////////////////////
        if(i!=0||i!=n-1){
            if(max<arr[i]){
                max=arr[i];
            }
            tmp+= arr[i]; 
        }
        //////////////////////
	}
    a=tmp+max;
//////////////
    for(int i=0;i<n;i++){
		if(2*arr[3]<arr[2]){
            if(i!=3){
                 tmpb+=2*arr[i];
            }
        }
        else{
          if(i!=2){
                 tmpb+=2*arr[i];
            } 
        }
	}
    ////////////////

    //////////////
    for(int i=0;i<n;i++){
		if(2*arr[n-1]<arr[n-2]){
            if(i!=n-1){
                 tmpc+=2*arr[i];
            }
        }
        else{
          if(i!=n-2){
                 tmpc+=2*arr[i];
            } 
        }
	}
    ////////////////
    if(tmp<=tmpb&&tmp<=tmpc){
        cout<<tmp+max<<endl;
    }
    else if(tmpb<=tmpc&&tmpb<=tmp){
        cout<<tmpb;
    }
    else if(tmpb<=tmpc&&tmpb<=tmp){
        cout<<tmpc;
    }
    
    return 0;
	
}
