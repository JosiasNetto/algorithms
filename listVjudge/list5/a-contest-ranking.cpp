#include <bits/stdc++.h>

using namespace std;

typedef struct graph {
    vector<vector<int>> matrix;
    vector<int> mark;
    vector<int> precedents;
    vector<string> arrayNames;
    int numEdges;
    int numVert;
} Graph;

Graph* create_graph(int n) {
    Graph* newGraph = new Graph;

    newGraph->numEdges = 0;
    newGraph->numVert = n;

    newGraph->mark.assign(n, 0);
    newGraph->precedents.assign(n, -1);
    newGraph->matrix.resize(n, vector<int>(n, 0));
    newGraph->arrayNames.clear();

    return newGraph;
}

int get_mark(Graph* g, int v1) {
    return g->mark[v1];
}

void set_edge(Graph* g, int v1, int v2) {
    if (g->matrix[v1][v2] == 0) {
        g->matrix[v1][v2] = 1;
        g->matrix[v2][v1] = 1;
        g->numEdges++;
    }
}

int first(Graph* g, int v) {
    for (int i = 0; i < g->arrayNames.size(); i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->arrayNames.size();
}

int next(Graph* g, int v, int w) {
    for (int i = w + 1; i < g->arrayNames.size(); i++) {
        if (g->matrix[v][i] != 0) {
            return i;
        }
    }
    return g->arrayNames.size();
}

int return_name_index(Graph* g, string name) {
    for (int i = 0; i < g->arrayNames.size(); i++) {
        if (g->arrayNames[i] == name) {
            return i;
        }
    }
    return g->numVert;
}

void add_name(Graph* g, string name) {
    if (g->arrayNames.size() < g->numVert) {
        g->arrayNames.push_back(name);
    }
}

int return_dist(Graph* g, int start, int goal) {
    int cnt = 0;
    int aux = start;

    while (aux != goal) {
        aux = g->precedents[aux];
        cnt++;
    }

    return cnt;
}

void BFS(Graph* g, int start, vector<pair<int, string>>& result) {
    queue<int> q;
    q.push(start);
    g->mark[start] = 1;
    result.push_back(make_pair(0, g->arrayNames[start]));

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        int w = first(g, v);
        while (w < g->arrayNames.size()) {
            if (get_mark(g, w) == 0) {
                g->mark[w] = 1;
                q.push(w);
                if (g->precedents[w] == -1) {
                    g->precedents[w] = v;
                }
                int aux = return_dist(g, w, start);
                result.push_back(make_pair(aux, g->arrayNames[w]));
            }
            w = next(g, v, w);
        }
    }
}

void sort_names(vector<string> v) {
  for (int i = v.size() - 1; i > 0; i--) {
        if (v[i] < v[i - 1]) {
            string aux = v[i];
            v[i] = v[i - 1];
            v[i - 1] = aux;
        } 
    }
    
  }


void graph_traversse_BFS(Graph* g, int start) {
    for (int i = 0; i < g->arrayNames.size(); i++) {
        g->mark[i] = 0;
        g->precedents[i] = -1;
    }
    vector<pair<int, string>> results;
    BFS(g, start, results);
    sort(results.begin(), results.end());

    for (const auto& res : results) {
        cout << res.second << " " << res.first << endl;
    }
    
    vector<string> rest(0);
    for (int i = 0; i < g->arrayNames.size(); i++) {
        if (g->mark[i] == 0) {
            rest.push_back(g->arrayNames[i]);
        }
    }

    sort(rest.begin(), rest.end());

    for(int i = 0; i < rest.size(); i++){
      cout<< rest[i] << " undefined" <<endl;
    }
}


int main() {
    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++) {
        int teams;
        cin >> teams;

        Graph* graph = create_graph(3 * teams);

        for (int j = 0; j < teams; j++) {
            string name1, name2, name3;
            cin >> name1 >> name2 >> name3;

            int indexName1 = return_name_index(graph, name1);
            if (indexName1 == graph->numVert) {
                add_name(graph, name1);
                indexName1 = graph->arrayNames.size() - 1;
            }

            int indexName2 = return_name_index(graph, name2);
            if (indexName2 == graph->numVert) {
                add_name(graph, name2);
                indexName2 = graph->arrayNames.size() - 1;
            }

            int indexName3 = return_name_index(graph, name3);
            if (indexName3 == graph->numVert) {
                add_name(graph, name3);
                indexName3 = graph->arrayNames.size() - 1;
            }

            set_edge(graph, indexName1, indexName2);
            set_edge(graph, indexName1, indexName3);
            set_edge(graph, indexName2, indexName3);
        }

        int indexProtagonist = return_name_index(graph, "Ahmad");
        cout << graph->arrayNames.size() << endl;
        graph_traversse_BFS(graph, indexProtagonist);

        delete graph;
    }

    return 0;
}
