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
  maior = max(maior, cnt);

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
  board[i][j] = 0;
}

int main(){
  int rows, count, maior;
  cin >> rows;
  count = 0;

while(rows != 0){
  int total;
  total = 0;
  maior = 0;
  count++;

  vector<vector<int> > board(10, vector<int>(10, -1));

  int cntValid = 0;
  for(int i = 0; i < rows; i++){
    int skiped, valid;
    cin >> skiped >> valid;
    total += valid;
    for(int j = skiped; j < skiped + valid; j++){
      board[i][j] = 0;
    }
  }
  jump_knight(0, 0, 1, maior, board);
  if(total - maior != 1){
    cout << "Case " << count <<", "<< total - maior << " squares can not be reached."<<endl;
  }
  else{
    cout << "Case " << count <<", "<< total - maior << " square can not be reached."<<endl;
  }
  cin >> rows;
}
}
