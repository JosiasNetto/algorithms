#include <bits/stdc++.h>

using namespace std;

typedef struct graph{
    int** matrix;
    int* mark;
    int numEdges;
    int numVertices;
    int* precedents;  //Declare the precedents array
}Graph;

Graph* create_graph(int n){
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));

    newGraph->mark = (int*) calloc(0, sizeof(int) * n);
    newGraph->precedents = (int*) malloc(sizeof(int) * n);  //Malloc the space for the precedents array
    for(int i = 0; i < n; i++){
      newGraph->precedents[i] = -1; //Declare all the itens of array as -1
    }

    newGraph->numEdges = 0;
    newGraph->numVertices = n;

    newGraph->matrix = (int**) malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        newGraph->matrix[i] = (int*) calloc(0, sizeof(int) * n);
    }

    return newGraph;
}

int first(Graph* g, int v){
    for(int i = 0; i < g->numVertices; i++){
        if(g->matrix[v][i] != 0){
            return i;
        }
    }
    return g->numVertices;
}

int next(Graph* g, int v, int w){
    for(int i = w + 1; i < g->numVertices; i++){
        if(g->matrix[v][i] != 0){
            return i;
        }
    }
    return g->numVertices;
}

void set_edge(Graph* g, int i, int j){
    if(g->matrix[i][j] == 0){
        g->numEdges++;
        g->numEdges++;
        g->matrix[i][j] = 1;
        g->matrix[j][i] = 1; 
    }
}

void del_edge(Graph* g, int i, int j){
    if(g->matrix[i][j] != 0){
        g->numEdges--;
        g->numEdges--;
        g->matrix[i][j] = 0;
        g->matrix[j][i] = 0;
    }
}

void set_mark(Graph* g, int v, int m){
    g->mark[v] = m;
}

int get_mark(Graph* g, int v){
    return g->mark[v];
}

//Func that return the path of one vertice to another in the graph
void return_path(Graph* g, int start, int final){ 
  int aux, count; //Declaring aux variables
  aux = final;  //Declaring the start vertice as the final
  count = 1;  //Variable that count the qtd of passed vertices until reach the wanted one

  stack<int> auxPrint;  //Stack to aux the print of the path

  /*This while iterates trought the precedents list, 
  starting at the final vertice, and checking his precedents until reach the start vertice */
  while(aux != start){
    auxPrint.push(aux); //Add the current vertice to the stack
    aux = g->precedents[aux]; //Decare aux as the precedent of the precedent
    count++;  //Increase the couunt of vertices in the path
  }
  
  auxPrint.push(aux); //Add the starter vertice to the stack

  for(int i = 0; auxPrint.size() != 0; i++){  //Loop that prints the path using the aux stack
    if(auxPrint.size() == 1){
      printf("%d", auxPrint.top());
    }
    else{
      printf("%d ", auxPrint.top());
    }
    auxPrint.pop();
  }
  
}

void BFS(Graph* g, int start, int goal){

    queue<int> q;
    q.push(start);
    set_mark(g, start, 1);
    int finish = 0;

    while(q.size() > 0 && finish == 0){
        int v = q.front();
        q.pop();

        int w = first(g, v);

        while(w < g->numVertices){
            if(get_mark(g, w) == 0){
                set_mark(g, w, 1);
                q.push(w);
                if(w == goal){
                    finish = 1;
                }
                if(g->precedents[w] == -1){ //If the vertice have no precedents, declare as the actual vertice
                  g->precedents[w] = v;
                }
            }
            w = next(g, v, w);  
        }
    }
    if(finish == 1){
      return_path(g, start, goal); //Calls the path func
    }
    else{
      printf("-1");
    }
}

void graph_traverse_BFS(graph* g, int v1, int v2){
    for(int i = 0; i < g->numVertices; i++){
        set_mark(g, i, 0);
        g->precedents[i] = -1;
    }
    BFS(g, v1, v2); 
}


int main(){


    int c;  //Recceive the number of cases 
    scanf("%d", &c);

    for(int i = 0; i < c; i++){ //Loops that iterate troghrt the number of cases

        printf("Caso %d\n", (i + 1)); //Print the current case

        int v, a;   //Declaring the vars of vertice number and edges number
        scanf("%d %d", &v, &a);
        
        Graph* g = create_graph(v);

        for(int j = 0; j < a; j++){ //Loop that receive the edges and set in the graph
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            set_edge(g, v1, v2);
        }

        int p;  //Number of paths to be tried
        scanf("%d", &p);

        for(int k = 0; k < p; k++){ //Loop that traverse the graph and print the path, if it exists
            int s, t;
            scanf("%d %d", &s, &t);
            if( s != t){
              graph_traverse_BFS(g, s, t);
            }
            else{
              printf("%d", s);
            }
            printf("\n");

        }
    }

    return 0;
}