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
  vector<vector<pair<int, int>>> matrix;
}Graph;

Graph* create_graph(int n){
  Graph* newGraph = new Graph;

  newGraph->numEdges = 0;
  newGraph->numVert = n;

  newGraph->mark.assign(n, 0);
  newGraph->dist.assign(n, inf);
  newGraph->parent.assign(n, -1);
  newGraph->matrix.resize(n);

  return newGraph;
}

void set_mark(Graph* g, int v, int m){
  g->mark[v] = m;
}

int get_mark(Graph* g, int v){
  return g->mark[v];
}

void set_edge(Graph* g, int v, int m, int wt){
  g->matrix[v].push_back({m, wt});
  g->matrix[m].push_back({v, wt});
  g->numEdges++;
}



void dijkstra(Graph* g, int s, int f){
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
    if(v == f){
      return;
    }
    
    int w;
    for(int i = 0; i < g->matrix[v].size(); i++){
      w =g->matrix[v][i].first;
      if(get_mark(g, w) != 1 && g->dist[w] > g->dist[v] + g->matrix[v][i].second){
        g->dist[w] = g->dist[v] + g->matrix[v][i].second;
        minHeap.push({g->dist[w],{v, w}});
      }
    }
  }
}


int main() {
  int numCase, numServer, numEdges, startServer, finalServer;

  cin>> numCase;

  for(int i = 0; i < numCase; i++){
    cin >> numServer >> numEdges >> startServer >> finalServer;

    Graph* g = create_graph(numServer);
    for(int j = 0; j < numEdges; j++){
      int v1, v2, wt;
      cin >> v1 >> v2  >> wt;
      set_edge(g, v1, v2, wt);
    }
    dijkstra(g, startServer, finalServer);
    if(g->dist[finalServer] != inf){
      cout << "Case #" << i + 1<< ": "<< g->dist[finalServer] << endl;
    }
    else{
      cout << "Case #" << i + 1<< ": unreachable"<< endl;
    }
  }

}