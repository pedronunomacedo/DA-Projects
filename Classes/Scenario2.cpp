//
// Created by gonzallito on 31-05-2022.
//

// Number of vertices in given graph
#define V 7


#include <climits>
#include "Scenario2.h"
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

Scenario2::Scenario2() {

}

int Scenario2::Scenario2_1() {
}

int Scenario2::scenario2_2(vector<vector<int> > graph, int s, int t)
{
    int u, j;

    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    vector<vector<int> > rGraph(51 , vector<int> (51)); // Residual graph where rGraph[i][j]



    // indicates residual capacity of edge
    // from i to j (if there is an edge. If
    // rGraph[i][j] is 0, then there is not)
    for (u = 1; u <= V; u++) {
        for (j = 1; j <= V; j++) {
            rGraph[u][j] = graph[u][j];
        }
    }

    int parent[V]; // This array is filled by BFS and to
    // store path

    int max_flow = 0; // There is no flow initially
    int numPersons = 3; // Ask the user for a number!!!!!!

    // Augment the flow while there is path from source to
    // sink
    while (bfs(rGraph, s, t, parent) && max_flow < numPersons) {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (j = t; j != s; j = parent[j]) {
            u = parent[j];
            path_flow = min(path_flow, rGraph[u][j]);
        }

        // update residual capacities of the edges and
        // reverse edges along the path
        for (j = t; j != s; j = parent[j]) {
            u = parent[j];
            rGraph[u][j] -= path_flow;
            rGraph[j][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}





/* Returns true if there is a path from source 's' to sink
  't' in residual graph. Also fills parent[] to store the
  path */
bool Scenario2::bfs(vector<vector<int> > rGraph, int s, int t, int parent[]) {
    // Create a visited array and mark all vertices as not
    // visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    // Create a queue, enqueue source vertex and mark source
    // vertex as visited
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                // If we find a connection to the sink node,
                // then there is no point in BFS anymore We
                // just have to set its parent and can return
                // true
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    // We didn't reach sink in BFS starting from source, so
    // return false
    return false;
}

// 2.3
int Scenario2::scenario2_3(vector<vector<int> > graph, int s, int t)
{
    int u, j;

    // Create a residual graph and fill the residual graph
    // with given capacities in the original graph as
    // residual capacities in residual graph
    vector<vector<int> > rGraph(51 , vector<int> (51)); // Residual graph where rGraph[i][j]



    // indicates residual capacity of edge
    // from i to j (if there is an edge. If
    // rGraph[i][j] is 0, then there is not)
    for (u = 1; u <= V; u++) {
        for (j = 1; j <= V; j++) {
            rGraph[u][j] = graph[u][j];
        }
    }

    int parent[V]; // This array is filled by BFS and to
    // store path

    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is path from source to
    // sink
    while (bfs(rGraph, s, t, parent)) {
        // Find minimum residual capacity of the edges along
        // the path filled by BFS. Or we can say find the
        // maximum flow through the path found.
        int path_flow = INT_MAX;
        for (j = t; j != s; j = parent[j]) {
            u = parent[j];
            path_flow = min(path_flow, rGraph[u][j]);
        }

        // update residual capacities of the edges and
        // reverse edges along the path
        for (j = t; j != s; j = parent[j]) {
            u = parent[j];
            rGraph[u][j] -= path_flow;
            rGraph[j][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}
