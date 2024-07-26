#include <bits/stdc++.h>

using namespace std;

bool jump_knight(int row, vector<vector<int> > board){
  if(row == board.size()){
    return true;
  }
  else{
    for(int i = 0; i < 8; i++){

    }
  }

}

int main(){
  int rows, cnt;
  cin >> rows;
  cnt = 0;

while(rows){
    int board[10][10];
    cnt++;

    int skiped, valid, cntValid;
    cntValid = 0;
    for(int i = 0; i < rows; i++){
      cin >> skiped >> valid;
      for(int j = 0; j < 10; j++){
        if(j < skiped){
          board[i][j] = -1;
        }
        else if(cntValid < valid){
          board[i][j] = 0;
          cntValid++;
        }
        else{
          board[i][j] = -1;
        }
      }
    }
    cin >> rows;
  }
}
