#include <bits/stdc++.h>

using namespace std;

typedef struct graph{
    int** matrix;
    int* mark;
    int numEdges;
    int numVertices;
}Graph;

Graph* create_graph(int n){
    Graph* newGraph = (Graph*) malloc(sizeof(Graph));

    newGraph->mark = (int*) calloc(0, sizeof(int) * n);
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
            }

            w = next(g, v, w);
            
        }
    }
}


void graph_traverse_BFS(graph* g, int v1, int v2){
    for(int i = 0; i < g->numVertices; i++){
        set_mark(g, i, 0);
    }
    
    BFS(g, v1, v2); 
    
}


int main(){


    int c;
    scanf("%d", &c);

    for(int i = 0; i < c; i++){

        printf("Caso %d\n", (i + 1));

        int v, a;
        scanf("%d %d", &v, &a);
        
        Graph* g = create_graph(v);

        for(int j = 0; j < a; j++){
            int v1, v2;
            scanf("%d %d", &v1, &v2);
            set_edge(g, v1, v2);
        }

        int p;
        scanf("%d", &p);

        for(int k = 0; k < p; k++){
            int s, t;
            scanf("%d %d", &s, &t);
            graph_traverse_BFS(g, s, t);
        }
    }

    return 0;
}