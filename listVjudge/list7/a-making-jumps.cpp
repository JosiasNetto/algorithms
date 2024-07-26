#include <bits/stdc++.h>

using namespace std;

bool valid(int i, int j, vector<vector<int> > board){
  if(i < 0 || j < 0 || i > 9 || j > 9 || board[i][j] == -1 || board[i][j] == 1){
    return false;
  }
  return true;
}

bool jump_knight(int i,int j, vector<vector<int> > board){
  if(valid(i - 2, j - 1, board)){
    
  }
  else if(valid(i - 2, j + 1, board)){

  }
  else if(valid(i - 1, j - 2, board)){

  }
  else if(valid(i - 1, j + 2, board)){

  }
  else if(valid(i + 1, j - 2, board)){

  }
  else if(valid(i + 1, j + 2, board)){

  }
  else if(valid(i + 2, j - 1, board)){

  }
  else if(valid(i + 2, j + 1, board)){

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
