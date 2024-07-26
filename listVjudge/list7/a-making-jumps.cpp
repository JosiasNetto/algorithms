#include <bits/stdc++.h>

using namespace std;

int main(){
  int rows, cnt;
  cin >> rows;
  cnt = 0;

while(rows){
    vector<vector<int> > board(rows);
    cnt++;

    int skiped, valid;
    for(int i = 0; i < rows; i++){
      cin >> skiped >> valid;
      board[i].assign(skiped, -1);
      for(int j = 0; j < valid; j++){
        board[i].push_back(0);
      }
    }
    cin >> rows;
  }
}
