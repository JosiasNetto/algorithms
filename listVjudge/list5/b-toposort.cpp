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
    for(int i = 0; i < n; i++){
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