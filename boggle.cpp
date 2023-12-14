#include <iostream>
using namespace std;


char word[50][11];
char boggle[6][6];


int dir8(int x, int y){
  if(boggle[x+1][y+1]==){

  }
  if(boggle[x-1][y+1]==){

    }
  if(boggle[x][y+1]==){

  }
  if(boggle[x][y-1]==){

  }
  if(boggle[x-1][y-1]==){

  }
  if(boggle[x+1][y-1]==){

  }
  if(boggle[x+1][y]==){

  }
  if(boggle[x-1][y]==){
} 


int main(void) {
  int tcase;
  int wordn;
  cin>>tcase;
  for(int t=0;t<tcase;t++){
    for(int i=0;i<5;i++){ //판 입력받기
      cin>>boggle[i];
    }
    cin>>wordn; //단어 개수 입력받기
    for(int i=0;i<wordn;i++){ //단어 입력받기
      cin>>word[i]; 
    }

    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
        dir8(i,j,cnt);
      }
    }

  
  }
}
