#include <bits/stdc++.h>

using namespace std;

#define inf INT_MAX

typedef struct graph{
    int numEdges;
    int numVert;

    vector<int> mark;
    vector<int> dist;
    vector<int> parent;
    vector<vector<pair<int,int>>> l;
}Graph;

Graph* create_graph(int n){
    Graph* newGraph = new Graph;

    newGraph->numEdges = 0;
    newGraph->numVert = n;

    newGraph->mark.assign(n, 0);
    newGraph->dist.assign(n, inf);
    newGraph->parent.assign(n, -1);
    newGraph->l.resize(n);

    return newGraph;
}

void set_edge(Graph* g, int v, int m, int wt){
    g->l[v].push_back({m, wt});
    g->l[m].push_back({v, wt});
    g->numEdges++;
}

void set_mark(Graph* g, int v, int m){
    g->mark[v] = m;
}

int get_mark(Graph* g, int v){
    return g->mark[v];
}

int first(Graph* g, int v){
    if(g->l[v].size()> 0){
     return g->l[v][0].first;
    }

    return g->numVert;
}

int next(Graph* g, int v, int m){
    int aux;
    for(int i = 0; i < g->l[v].size(); i++){
        if(g->l[v][i].first == m && g->l[v].size() > i + 1){
            return g->l[v][i + 1].first;
        }
    }
    return g->numVert;
}

int weight(Graph* g, int v, int m){
    for(int i = 0; i < g->l[v].size(); i++){
        if(g->l[v][i].first == m){
            return g->l[v][i].second;
        }
    }

    return inf;
}

void Prim(Graph* g){
    for(int i = 0; i < g->numVert; i++){
        g->dist[i] = inf;
        g->parent[i] = -1;
        set_mark(g, i, 0);
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    minHeap.push({0, {0, 0}});
    g->dist[0] = 0;

    int p, v;
    

    for(int i = 0; i < g->numVert; i++){
        do{
            if(minHeap.empty()){
                return;
            }
            p = minHeap.top().second.first;
            v = minHeap.top().second.second;
            minHeap.pop();
        }
        while(get_mark(g, v));

        set_mark(g, v, 1);
        g->parent[v] = p;


        int w = first(g, v);
        while(w < g->numVert){
            if(get_mark(g, w) != 1 && g->dist[w] > weight(g, v, w)){
                g->dist[w] = weight(g, v, w);
                minHeap.push({g->dist[w],{ v, w}});
            }
            w = next(g, v, w);
        }
    }
    
}

int sum_dist(Graph* g){
    int sum = 0;
    for(int i = 0; i < g->numVert; i++){
        if(g->dist[i] != inf){
            sum += g->dist[i];
        }
    }
    return sum;
}


int main(){

    int cities, roads, count;
    cin>>cities >> roads;

    bool finish = false;
    count = 0;

    if(cities == 0 && roads == 0){
        finish = true;
    }
    while(!finish){
        count++;
        Graph* g = create_graph(cities);

        for(int i = 0; i < roads; i++){
            int v1, v2, wt;
            cin>> v1>> v2>> wt;
            set_edge(g, v1, v2, wt);
        }

        Prim(g);
        cout<<  "Caso "<< count << ": " << sum_dist(g)<< endl;
    
        cin>>cities >> roads;
        if(cities == 0 && roads == 0){
        finish = true;
        }
    }
    return 0;
}