#include <bits/stdc++.h>

using namespace std;

#define UNVISITED 0

typedef struct graph{
    int numEdges;
    int numVert;

    vector<int> mark;
    vector<list<int>*> matrix;
}Graph;

Graph* create_graph(int n){
    Graph* newGraph = new Graph;

    newGraph->numEdges = 0;
    newGraph->numVert = n;

    newGraph->mark.assign(n, UNVISITED);
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
    g->matrix[v]->clear();
}

void toposort(Graph* g){
    priority_queue<int, vector<int>, greater<int> > minHp;
    vector<int> results;

    for(int i = 0; i < g->numVert; i++){
        if(get_mark(g, i) == 0 && no_points(g, i) == 0){
            minHp.push(i);
        }
    }

    while(minHp.size() > 0){
        int v = minHp.top();
        minHp.pop();
        results.push_back(v + 1);

    }
}

int main(){
    int vert, edges;
    cin>> vert >> edges;

    Graph* graph = create_graph(vert);

    for(int i = 0; i < edges; i++){
        int v1, v2;
        cin>> v1>> v2;
        set_edge(graph,v1 - 1, v2 - 1);
    }
    
}