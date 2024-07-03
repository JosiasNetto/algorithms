#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//Graph structure
typedef struct graph{
  int** matrix; //Matrix of adjacency
  int numEdge;  //Number of edges of the graph
  int* Mark;  //List of visited vertices
  int numVertex; //Number of vertices
}Graph;

//Func that create a graph of n vertices
Graph* create_graph(int n){
  Graph* newGraph = (Graph*) malloc(sizeof(Graph)); //Declaring the new graph. Malloc a space in the heap to the graph struct and point to him
  newGraph->Mark = (int*) malloc(sizeof(int) * n);  //Declare the size of the array of visited vertices
  newGraph->matrix = (int**) malloc(sizeof(int*) * n);  //Declare the size of the matrix of adjacency(A array that points to arrays)

  newGraph->numEdge = 0;  //Declare the start number of edges
  newGraph->numVertex = n; //Declare the number of verte=ices of the fraph

  return newGraph;  //Return the created graph
}

//Func that return the first adjacent vertice of one given vertex
int first(Graph* g, int v){
  for(int i = 0; i < (sizeof(g->matrix[v])/sizeof(int)) -1 ; i++){  //For that iterates by the row of the given vertex
    if(g->matrix[v][i] != 0){ //Check if the item is adjacent
      return i; //Return the adjacent item
    }
  }
  return sizeof(g->matrix[v])/sizeof(int);  //If not have adjacents, return the number of vertices
}

//Func that return the next adjacent vertice of a given vertice, starting by an another adjacent given vertice
int next(Graph* g, int v, int w){
  for(int i = w + 1; i < (sizeof(g->matrix[v])/sizeof(int)) - 1; i++){  //For that iterates by the row of the given vertex, starting in the given adjacent
    if(g->matrix[v][i] != 0){ //Check if the item is adjacent
      return i; //Return the adjacent vertice
    }
  }
  return sizeof(g->matrix[v])/sizeof(int);  //If does not have adjacents, return the number of vertices
}

//Func that set an edge between two vertices
void set_edge(Graph* g, int i, int j, int wt){
  if(wt == 0){
    return;
  }
  if(g->matrix[i][j] == 0){ //Check if the item does not have and edge
    g->numEdge++; //Increase the number of edges
    g->matrix[i][j] = wt; //Declare the item of the matrix as the passed weight
  }
}

//Func that delete a edge of the graph
void del_edge(Graph* g, int i, int j){
  if(g->matrix[i][j] != 0){ //Check if the vertices are adjacents
    g->numEdge--; //Decrease the number of edges
    g->matrix[i][j] = 0;  //Set the item in the adjacency matrix as 0
  }
}

//Func that change the value of a vertice in the marked array
void set_mark(Graph* g, int v, int mark){
  g->Mark[v] = mark;
}

//Func that return the value of a vertice in the marked array
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

void BFS(Graph* g, int start){
}




//Func to traverse the graph with the DFS algorithm
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

int main(){

  printf("Oi");

  return 0;
}