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
  newGraph->Mark = (int*) calloc(0, sizeof(int) * n);  //Declare the size of the array of visited vertices
  newGraph->matrix = (int**) malloc(sizeof(int*) * n);  //Declare the size of the matrix of adjacency(A array that points to arrays)

  newGraph->numEdge = 0;  //Declare the start number of edges
  newGraph->numVertex = n; //Declare the number of verte=ices of the fraph

  for(int i = 0; i < newGraph->numVertex; i++){
    newGraph->matrix[i] = (int*) calloc(0, sizeof(int) * n);
  }

  return newGraph;  //Return the created graph
}

//Func that return the first adjacent vertice of one given vertex
int first(Graph* g, int v){
  for(int i = 0; i < g->numVertex; i++){  //For that iterates by the row of the given vertex
    if(g->matrix[v][i] != 0){ //Check if the item is adjacent
      return i; //Return the adjacent item
    }
  }
  return g->numVertex;  //If not have adjacents, return the number of vertices
}

//Func that return the next adjacent vertice of a given vertice, starting by an another adjacent given vertice
int next(Graph* g, int v, int w){
  for(int i = w + 1; i < g->numVertex; i++){  //For that iterates by the row of the given vertex, starting in the given adjacent
    if(g->matrix[v][i] != 0){ //Check if the item is adjacent
      return i; //Return the adjacent vertice
    }
  }
  return g->numVertex;  //If does not have adjacents, return the number of vertices
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

//Func that does something in the start of the traverse  of one vertice
void pre_visit(Graph* g, int v){
  printf("Oi %d\n", v);
}

//Func that does something in the exit of the traverse of one vertice
void pos_visit(Graph* g, int v){
  printf("Tchau %d\n", v);
}

//Algorithm of DFS
void DFS(Graph* g, int v){  //Receive the graph and the starter vertex as arguments
  pre_visit(g, v);  //Calls the pre visit func
  set_mark(g, v, 1);  //Mark the start vertice as visited
  int w = first(g, v);  //Declare w as the firt adjacent vertex of v
  while(w < g->numVertex){  //Loop that pass trought all the adjacent vertices of v
    if(get_mark(g, w) == 0){  //Check if the vertices was already visited
      DFS(g, w);  //If is a unvisited vertice, call the func again
    }
    w = next(g, v, w);  //Go to te next adjacent vertice
  }
  pos_visit(g, v);  //When exit of the vertice
}

//Algorithm of BFS
void BFS(Graph* g, int start){  //Receive tthe graph and the starter vertex as arguments
  queue<int> q; //Declaring the queue that bases the algorithm
  q.push(start);  //Add the start vertice to the queue
  set_mark(g, start, 1);  //Set the start vertice as visited

  while(q.size() > 0){  //While that passes trought all connected vertices of the graph
    int v = q.front();  //Declare the current vertice as the front of the queue
    q.pop();  //Pop the front vertice of the queue
    pre_visit(g, v);  //Calls the previsit func
    int w = first(g, v);  //Declare the first adjacent vertice of the v vertex  

    while(w < g->numVertex){  //Loop that goes trought all the adjacent vertex of v
      if(get_mark(g, w) == 0){  //Check if it is a already visited vertice
        set_mark(g, w, 1);  //Set as visited
        q.push(w);  //Enqueue the vertice
      }
      w = next(g, v, w);  //Declare as the next adjacent vertex
    }
    pos_visit(g, v);  //Calls the pos visit func
  }
}

//Func to traverse the graph with the DFS algorithm
void graph_travers_DFS(Graph* g){
  for(int i = 0; i < g->numVertex; i++){  //For that declare all the vertices unvisited
    set_mark(g, i, 0);
  }
  for(int i = 0; i < g->numVertex; i++){  //For that pass trought all the vertices of the graph
    if(get_mark(g, i) == 0){
      DFS(g, i);
    }
  }
}

//Func that traverse the graph with the BFS algorithm
void graph_travers_BFS(Graph* g){
  for(int i = 0; i < g->numVertex; i++){  //For that declare all the vertices unvisited
    set_mark(g, i, 0);
  }
  for(int i = 0; i < g->numVertex; i++){  //For that pass trought all the vertices of the graph
    if(get_mark(g, i) == 0){
      BFS(g, i);
    }
  }
}

int main(){


  int numberVertex;
  scanf("%d", &numberVertex);
  Graph* newGraph = create_graph(numberVertex); 

  int numberEdges;
  scanf("%d" ,&numberEdges);
  for(int i = 0; i < numberEdges; i++){
    int vert1, vert2;
    scanf("%d %d", &vert1, &vert2);
    set_edge(newGraph, vert1, vert2, 1);
  }

  graph_travers_BFS(newGraph);


  return 0;
}