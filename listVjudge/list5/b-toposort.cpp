#include <bits/stdc++.h>

using namespace std;

#define UNVISITED 0

typedef struct graph{
    int numEdges;
    int numVert;

    vector<int> mark;
    vector<int> inDegree;
    vector<list<int>*> matrix;
}Graph;

Graph* create_graph(int n){
    Graph* newGraph = new Graph;

    newGraph->numEdges = 0;
    newGraph->numVert = n;

    newGraph->mark.assign(n, UNVISITED);
    newGraph->inDegree.assign(n, 0);
    for(int i = 0; i < n + 1; i++){
        newGraph->matrix.push_back(new list<int>);
    }

    return newGraph;
}

void set_mark(Graph* g, int v, int m){
    g->mark[v] = m;
}

int get_mark(Graph* g, int v){
    return g->mark[v];
}

void set_edge(Graph* g, int v, int w){
    auto it = find(g->matrix[v]->begin(), g->matrix[v]->end(), w);
    if(it == g->matrix[v]->end()){
        g->matrix[v]->push_back(w);
        g->numEdges++;
    }
}

int first(Graph* g, int v){
    if(!g->matrix.empty()){
        return g->matrix[v]->front();
    }
    else{
        return g->numVert;
    }
}

int next(Graph* g, int v, int w){
    auto it = find(g->matrix[v]->begin(), g->matrix[v]->end(), w);
    if(it != g->matrix[v]->end()){
        return *it;
    }
    else{
        return g->numVert;
    }
}

int no_points(Graph* g, int v){
    for(int i = 0; i < g->numVert; i++){
        if(find(g->matrix[i]->begin(), g->matrix[i]->end(), v) != g->matrix[i]->end()){
            return 1;
        }
    }
    return 0;
}

void clear_list(Graph* g, int v){
    for(int w : *g->matrix[v]){
      g->inDegree[w]--;
    }

    g->numEdges = g->numEdges - g->matrix[v]->size();
    g->matrix[v]->clear();
}

void toposort(Graph* g){
    priority_queue<int, vector<int>, greater<int> > minHp;
    vector<int> results;
    int cnt = 0;
    int found = 0;

    for(int j = 0; j < g->numVert; j++){
      cnt = 0;
      found = 0;
      while(cnt < g->numVert && found == 0){
          if(get_mark(g, cnt) == 0 && g->inDegree[cnt] == 0){
              minHp.push(cnt);
              set_mark(g, cnt, 1);
              found = 1;
          }
          cnt++;
      }

      if(minHp.size() == 0 && g->numEdges > 0){
        cout<< "Sandro fails.";
        return;
      }

      while(minHp.size() > 0){
          int v = minHp.top();
          minHp.pop();
          results.push_back(v + 1);
          clear_list(g, v);

      }
    }
    for(int i = 0; i < results.size(); i++){
      cout<< results[i]<< " ";
    }

}

int main(){
    int vert, edges;
    cin>> vert >> edges;

    Graph* graph = create_graph(vert);

    for(int i = 0; i < edges; i++){
        int v1, v2;
        cin>> v1>> v2;
        set_edge(graph,v1 -1 , v2 -1);
        graph->inDegree[v2 - 1]++;
    }

    toposort(graph);
    
}