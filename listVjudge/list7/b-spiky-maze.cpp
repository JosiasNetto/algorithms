#include <bits/stdc++.h>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool valid(vector<vector<char>>& maze, int avoidSpikes, pair<int,int> cord){
    if(cord.first >= 0 && cord.first < maze.size() && cord.second >= 0 && cord.second < maze[0].size()){
        if(maze[cord.first][cord.second] != '#'){
            if(maze[cord.first][cord.second] == 's' && avoidSpikes > 0){
                return true;
            }
            if(maze[cord.first][cord.second] != 's'){
                return true;
            }
        }
    }
    return false;
}

bool solve_maze(vector<vector<char>>& maze, int avoidSpikes, pair<int, int> cord){
    if(maze[cord.first][cord.second] == 'x'){
        return true;
    }
    if(maze[cord.first][cord.second] == 's'){
        avoidSpikes--;
    }
    char aux =  maze[cord.first][cord.second];
    maze[cord.first][cord.second] = '#';

    for(auto it = 0; it < 4; it++){
        int x = cord.first + dx[it];
        int y = cord.second + dy[it];
        if(valid(maze, avoidSpikes, {x, y})){
            if(solve_maze(maze, avoidSpikes, {x, y})){
                return true;
            }
        }
    }
    maze[cord.first][cord.second] = aux;
    return false;
}

int main(){
    int Rows, Colums, spikesAvoid;
    cin>> Rows>> Colums>> spikesAvoid;
    spikesAvoid = floor(spikesAvoid / 2);
    
    vector<vector<char>> maze(Rows, vector<char>(Colums));
    pair<int, int> entrace;

    for(int i = 0; i < Rows; i++){
        for(int j = 0; j < Colums; j++){
            char obj;
            cin>> obj;
            maze[i][j] = obj;
            if(obj == '@'){
                entrace = {i, j};
            }
        }
    }
    if(solve_maze(maze, spikesAvoid, entrace)){
        cout << "SUCCESS";
    }
    else{
        cout << "IMPOSSIBLE";
    }

}