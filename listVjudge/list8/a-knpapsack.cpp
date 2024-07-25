#include <bits/stdc++.h>

using namespace std;

int max_item(int a, int b){
  if(a >= b){
    return a;
  }
  else{
    return b;
  }
}

int knapsack_bottom_up(int n, int w, vector<pair<int,int> > items, vector<vector<int> >& matrix){
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= w; j++){
      if(items[i - 1].first <= j){
        matrix[i][j] = max_item(matrix[i - 1][j], items[i -1].second + matrix[i -1][j - items[i - 1].first]);
      }
      else{
        matrix[i][j] = matrix[i -1][j];
      }
    }
  }
  return matrix[n][w];
}

int knapsack_top_down(int i, int j, vector<pair<int,int> > items, vector<vector<int> >& matrix){
  int value;
  if(i < 0 || j < 0){
    return 0;
  }
  if(matrix[i][j] < 0){
    if(j < items[i].first){
      value = knapsack_top_down(i - 1, j, items, matrix);
    }
    else{
      value = max_item(knapsack_top_down(i - 1, j, items, matrix), items[i].second + knapsack_top_down(i - 1, j - items[i].first, items, matrix));
    }
    matrix[i][j] = value;
  }
  return matrix[i][j];
}

int main(){
  int size, numItems;
  cin >> size >> numItems;

  vector<pair<int, int> > items(numItems);
  vector<vector<int> > matrix(numItems + 1, vector<int>(size + 1, -1));

  int weight, value;
  for(int i = 0; i < numItems; i++){
    cin >> weight >> value;
    items[i] = {weight, value};
  }

  int valueTotal = knapsack_top_down(numItems, size, items, matrix);
  cout << valueTotal << endl;

  return 0;
}