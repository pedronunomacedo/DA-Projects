//
// Created by gonzallito on 31-05-2022.
//


#include <stack>
#include <set>
#include "Scenario2.h"
#include "graph.h"

Scenario2::Scenario2() {
    g.readData("../files/Tests_B/in01_b.txt");
    stops = g.getStops();
}

void Scenario2::setNrVertices(int v) {
    no_vertices = v;
}

void Scenario2::printPath(vector<int> &parent, int source, int target) {
    vector<int> path;
    for (int i = target; i > source; i = (parent[i-1]+1)) {
        path.push_back(parent[i-1]+1);
        if(parent[i-1]+1 == source)
            break;
    }
    reverse(path.begin(), path.end());
    for (int i : path) {
        cout << i << "--";
    }
    cout << target;
}

bool Scenario2::bfs(vector<vector<int> > &rGraph, int s, int t, vector<int> &parent) {

    bool visited[rGraph.size()];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s-1);
    visited[s-1] = true;
    parent[s-1] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < rGraph.size(); v++) {
            if (!visited[v] && rGraph[u][v] > 0) {

                if (v == (t-1)) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

void Scenario2::scenario2_1(vector<vector<int> > graph, int s, int t, int size) {
    g.readData("../files/Tests_B/in01_b.txt");
    stops = g.getStops();
    int u, j;

    vector<vector<int> > rGraph(graph.size()-1 , vector<int> (graph.size()-1)); // Residual graph where rGraph[i][j]

    for (u = 0; u < graph.size()-1; u++) {
        for (j = 0; j < graph.size()-1; j++) {
            rGraph[u][j] = graph[u][j];
        }
    }

    vector<int> parent(graph.size()-1, 0);

    int max_flow = 0;
    int numPeople = size;


    while (bfs(rGraph, s, t, parent) && max_flow < numPeople) {

        int path_flow = INT_MAX;
        for (j = t-1; j != s-1; j = parent[j]) {
            u = parent[j];
            path_flow = min(path_flow, rGraph[u][j]);
        }

        for (j = t-1; j != s-1; j = parent[j]) {
            u = parent[j];
            rGraph[u][j] -= path_flow;
            rGraph[j][u] += path_flow;
        }

        max_flow += path_flow;
    }

    for (int i = 0; i < rGraph.size(); i++) {
        for (Bus e : stops[i].adj) {
            int e_flow = rGraph[e.dest-1][i];
            if (e_flow > 0) {
                cout << i+1 << "---->" << e.dest << "     flow: "  << e_flow << endl;
            }
        }
    }

    //cout << " The path is: ";
    //printPath(parent, s, t); cout << endl;
}

void Scenario2::scenario2_2(vector<vector<int>> graph, int s, int t, int size) {
    scenario2_1(graph, s, t, size);
}

void Scenario2::scenario2_3(vector<vector<int> > graph, int s, int t) {
    int u, j;

    vector<vector<int> > rGraph(graph.size()-1 , vector<int> (graph.size()-1));

    for (u = 0; u < graph.size()-1; u++) {
        for (j = 0; j < graph.size()-1; j++) {
            rGraph[u][j] = graph[u][j];
        }
    }

    vector<int> parent(graph.size()-1, 0);

    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {

        int path_flow = INT_MAX;
        for (j = t-1; j != s-1; j = parent[j]) {
            u = parent[j];
            path_flow = min(path_flow, rGraph[u][j]);
        }

        for (j = t-1; j != s-1; j = parent[j]) {
            u = parent[j];
            rGraph[u][j] -= path_flow;
            rGraph[j][u] += path_flow;
        }

        max_flow += path_flow;
    }

    for (int i = 0; i < rGraph.size(); i++) {
        for (Bus e : stops[i].adj) {
            int e_flow = rGraph[e.dest-1][i];
            if (e_flow > 0) {
                cout << i+1 << "---->" << e.dest << "     flow: "  << e_flow << endl;
            }
        }
    }

    cout << endl;
    cout << "The max flow is: " << max_flow << endl ;
}

void Scenario2::scenario2_4(vector<vector<int>> graph){
    queue<int> fila;
    int n = g.getNrStops();
    for(int v = 1; v <= n; v++) {
        stops[v].ES= 0; // data + proxima p/ caminhos com inicio em v
        stops[v].pred= 0; // nó anterior do v é 0
        stops[v].GrauE = 0; //grau entrada do v
    }

    for(int v = 1; v <= n; v++) {
        for(auto a : stops[v].adj) {
            stops[a.dest-1].GrauE++;
        }
    }

    for(int v = 1; v <= n; v++) {
        if(stops[v].GrauE != 0)
            fila.push(v);
    }

    //set<int> paragens = {1, 3, 6, 8, 9, 12, 19, 21, 22, 23, 29, 31, 33, 38, 39, 41, 44, 45, 46, 50};
    set<int> paragens = {1, 6, 8, 38, 33, 10, 46, 48, 27, 36, 50, 39, 44, 40, 22, 41, 45, 17, 35, 29, 31, 19, 12};



    int duracaominima = -1;
    int x;
    while (!fila.empty()) {
        x = fila.front();
        fila.pop();
        if (duracaominima < stops[x].ES){
            duracaominima = stops[x].ES;
        }
        for(auto a : stops[x].adj) {
            if (paragens.find(a.dest) != paragens.end()) {
                if (stops[a.dest - 1].ES < stops[a.dest - 1].ES + a.duration) {
                    stops[a.dest - 1].ES = stops[a.dest - 1].ES + a.duration;
                    stops[a.dest - 1].pred = x;
                }
            }
            stops[a.dest-1].GrauE = stops[a.dest-1].GrauE--;

            if(stops[a.dest-1].GrauE == 0) {
                fila.push(a.dest);
            }
        }

        /*for(int v = 0; v < pilha.size(); v++) {
            if(duracaominima < stops[v+1].ES) {
                duracaominima = stops[v+1].ES;
            }

            for(int v = 1; v <= n; v++) {
                for(auto a : stops[v].adj) {
                    if (paragens.find(a.dest) != paragens.end()) {
                        if (stops[a.dest - 1].ES < stops[a.dest - 1].ES + a.duration) {
                            stops[a.dest - 1].ES = stops[a.dest - 1].ES + a.duration;
                            stops[a.dest - 1].pred = v;
                        }
                    }
                    stops[a.dest-1].GrauE = stops[a.dest-1].GrauE--;

                    if(stops[a.dest-1].GrauE == 0) {
                        pilha.push(a.dest-1);
                    }
                }
            }
        }*/
    }
    cout << duracaominima;

}

void Scenario2::scenario2_5(vector<vector<int>> graph, int s, int t) {

}
