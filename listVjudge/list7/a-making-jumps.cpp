#include <bits/stdc++.h>

using namespace std;

bool valid(int i, int j, vector<vector<int> >& board){
  if(i < 0 || j < 0 || i > 9 || j > 9 || board[i][j] == -1 || board[i][j] == 1){
    return false;
  }
  return true;
}

void jump_knight(int i,int j, int cnt, int& maior, vector<vector<int> >& board){
  board[i][j] = 1;
  if(valid(i - 2, j - 1, board)){
    jump_knight(i - 2, j - 1, cnt + 1, maior, board);
  }
  if(valid(i - 2, j + 1, board)){
    jump_knight(i - 2, j + 1, cnt + 1, maior, board);
  }
  if(valid(i - 1, j - 2, board)){
    jump_knight(i - 1, j - 2, cnt + 1, maior, board);
  }
  if(valid(i - 1, j + 2, board)){
    jump_knight(i - 1, j + 2, cnt + 1, maior, board);
  }
  if(valid(i + 1, j - 2, board)){
    jump_knight(i + 1, j - 2, cnt + 1, maior, board);
  }
  if(valid(i + 1, j + 2, board)){
    jump_knight(i + 1, j + 2, cnt + 1, maior, board);
  }
  if(valid(i + 2, j - 1, board)){
    jump_knight(i + 2, j - 1, cnt + 1, maior, board);
  }
  if(valid(i + 2, j + 1, board)){
    jump_knight(i + 2, j + 1, cnt + 1, maior, board);
  }
  if(cnt > maior){
    maior = cnt;
  }
  board[i][j] = 0;
}

int main(){
  int rows, cnt, maior;
  cin >> rows;
  cnt = 0;

while(rows != 0){
  int total;
  total = 0;
  maior = 0;

  vector<vector<int> > board(10, vector<int>(10, 0));
  cnt++;

  int skiped, valid, cntValid;
  cntValid = 0;
  for(int i = 0; i < rows; i++){
    cin >> skiped >> valid;
    total += valid;
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
  jump_knight(0, 0, 0, maior, board);
  if(cntValid - maior != 1){
    cout << "Case " << cnt <<" "<< maior << " squares can not be reached."<<endl;
  }
  else{
    cout << "Case " << cnt <<" "<< total - maior << " square can not be reached."<<endl;
  }
  cin >> rows;
}
}
