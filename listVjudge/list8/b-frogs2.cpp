#include <bits/stdc++.h>

using namespace std;

int jump_frog(int numStones, int maxDist,  int heightStones[]){
  int position;
  position = 0;
  vector<int> distStones(numStones, INT_MAX);
  distStones[0] = 0;

  for(int i = 0; i < numStones; i++){
    for(int j = 1; j < maxDist + 1; j++){
      if(i + j < numStones){
        distStones[i + j] = min(distStones[i + j], distStones[i] + abs(heightStones[i] - heightStones[i + j]));
      }
    }
  }
  return distStones[numStones - 1];
}

int main(){
  int numStones, maxDist;
  cin >> numStones>> maxDist;
  int heightStones[numStones];

  for(int i = 0; i < numStones; i++){
    int height;
    cin >> height;
    heightStones[i] = height;
  }
  cout<< jump_frog(numStones, maxDist, heightStones);


}