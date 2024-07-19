#include<bits/stdc++.h>

using namespace std;

#define inf INT_MAX
#define unvisited 0

typedef struct graph{
  int numEdges;
  int numVert;

  vector<int> mark;
  vector<int> dist;
  vector<int> parent;
  vector<vector<int>> matrix;
}Graph;

Graph* create_graph(int n){
  Graph* newGraph = new Graph;

  newGraph->numEdges = 0;
  newGraph->numVert = n;

  newGraph->mark.assign(n, 0);
  newGraph->dist.assign(n, inf);
  newGraph->parent.assign(n, -1);
  newGraph->matrix.resize(n, vector<int>(n, inf));\

  return newGraph;
}

void set_mark(Graph* g, int v, int m){
  g->mark[v] = m;
}

int get_mark(Graph* g, int v){
  return g->mark[v];
}

void set_edge(Graph* g, int v, int m, int wt){
  if(g->matrix[v][m] == inf){
    g->matrix[v][m] = wt;
    g->numEdges++;
  }
}

int first(Graph* g, int v){
  for(int i = 0; i < g->numVert; i++){
    if(g->matrix[v][i] != inf){
      return i;
    }
  }
  return g->numVert;
}

int next(Graph* g, int v, int w){
  for(int i = w + 1; i< g->numVert; i++){
    if(g->matrix[v][i] != inf){
    return i;
    }
  }
  return g->numVert;
}

int weight(Graph* g, int v, int w){
  return g->matrix[v][w];
}

void dijkstra(Graph* g, int s){
  for(int i = 0; i < g->numVert; i++){
    g->dist[i] = inf;
    g->parent[i] = -1;
    set_mark(g, i, unvisited);
  }

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int> >>> minHeap;
  minHeap.push({0, {s, s} });
  g->dist[s] = 0;

 int parent;
 int v;

  for(int i = 0; i < g->numVert; i++){
    do{
      if(minHeap.empty()){
        return;}
      parent = minHeap.top().second.first;
      v = minHeap.top().second.second;
      minHeap.pop();
      
    }
    while(get_mark(g, v) != 0);
    set_mark(g, v, 1);
    g->parent[v] = parent;
    
    int w = first(g, v);
    while(w != g->numVert){
      if(get_mark(g, w) != 1 && g->dist[w] > g->dist[v] + g->matrix[v][w]){
        g->dist[w] = g->dist[v] + g->matrix[v][w];
        minHeap.push({g->dist[w],{v, w}});
      }
      w = next(g, v, w);
    }
  }
}

int main() {
    Graph* g = create_graph(5);

    g->matrix[0][1] = 10;
    g->matrix[0][2] = 3;
    g->matrix[2][1] = 2;
    g->matrix[1][3] = 5;
    g->matrix[0][3] = 20;
    g->matrix[3][4] = 11;
    g->matrix[2][4] = 15;

    dijkstra(g, 0); 

    for (int i = 0; i < g->numVert; i++) {
        cout << "Distância até " << i << ": " << g->dist[i] << ", Pai: " << g->parent[i] << endl;
    }

    return 0;
}