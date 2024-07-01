#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

typedef struct graph{
  int** matrix;
  int numEdge;
  int* Mark;
}Graph;

Graph* create_graph(int n){
  Graph* newGraph = (Graph*) malloc(sizeof(Graph));
  newGraph->Mark = (int*) malloc(sizeof(int) * n);
  newGraph->matrix = (int**) malloc(sizeof(int*) * n);

  newGraph->numEdge = 0;

  return newGraph;
}

int first(Graph* g, int v){
  for(int i = 0; i < (sizeof(g->matrix[v])/sizeof(int)) -1 ; i++){
    if(g->matrix[v][i] != 0){
      return i;
    }
  }
  return sizeof(g->matrix[v])/sizeof(int);
}

int next(Graph* g, int v, int w){
  for(int i = w + 1; i < (sizeof(g->matrix[v])/sizeof(int)) - 1; i++){
    if(g->matrix[v][i] != 0){
      return i;
    }
  }
  return sizeof(g->matrix[v])/sizeof(int);
}

void set_edge(Graph* g, int i, int j, int wt){
  if(wt == 0){
  }
  if(g->matrix[i][j] == 0){
    g->numEdge++;
    g->matrix[i][j] = wt;
  }
}

void del_edge(Graph* g, int i, int j){
  if(g->matrix[i][j] != 0){
    g->numEdge--;
    g->matrix[i][j] = 0;
  }
}

void set_mark(Graph* g, int v, int mark){
  g->Mark[v] = mark;
}

int get_mark(Graph* g, int v){
  return g->Mark[v];
}

void DFS(Graph* g, int v){
  set_mark(g, v, 1);
  int w = first(g, v);
  while(w < sizeof(g->matrix[v])/sizeof(int)){
    if(get_mark(g, w) == 0){
      DFS(g, w);
    }
    w = next(g, v, w);
  }
}





void graph_travers_Dfs(Graph* g){
  for(int i = 0; i < sizeof(g->matrix[i])/sizeof(int); i++){
    set_mark(g, i, 0);
  }
  for(int i = 0; i < sizeof(g->matrix[i])/sizeof(int); i++){
    if(get_mark(g, i) == 0){
      DFS(g, i);
    }
  }
}