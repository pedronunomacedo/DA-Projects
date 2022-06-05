//
// Created by gonzallito on 31-05-2022.
//

// Number of vertices in given graph


#include <climits>
#include "Scenario2.h"
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

Scenario2::Scenario2() {

}

void Scenario2::setNrVertices(int v) {
    no_vertices = v;
}


void Scenario2::scenario2_1(vector<vector<int> > graph, int s, int t, int size)
{
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

    cout << "The path is: "; printPath2(parent, s, t); cout << endl;
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





int Scenario2::scenario2_3(vector<vector<int> > graph, int s, int t)
{
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

    cout << "The path is: "; printPath2(parent, s, t); cout << endl;
    cout << "     The max flow is: ";
    return max_flow;
}

void Scenario2::printPath2(vector<int> &parent, int source, int target) {
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

void Scenario2::scenario2_2(vector<vector<int>> graph, int s, int t, int size) {
    scenario2_1(graph, s, t, size);
}