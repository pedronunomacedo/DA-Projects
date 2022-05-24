#include "graph.h"

#include <list>
#include <string>
#include <queue>

Graph::Graph() {
    n = 0;
    hasDir = false;
    nodes.clear();
}

Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num + 1) {}

// ---------------------------------------------------------------------------------------------------

void Graph::bfs(int s) {
    for (int v = 1; v <= n; v++)
        nodes[v]. visited = false;

    queue<int> q;
    q.push(s);
    nodes[s].visited = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto &e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].pred = u;
            }
        }
    }
}

// ---------------------------------------------------------------------------------------------------

void Graph::addEdge(const pair<int,string> &src, const pair<int,string> &dest, const string &lineCode) {
    if (src.first < 1 || src.first > n || dest.first < 1 || dest.first > n)
        return;

    nodes[src.first].adj.push_back({dest.first,lineCode});

    if (!hasDir)
        nodes[dest.first].adj.push_back({src.first});
}


// ---------------------------------------------------------------------------------------------------

// Created by Utilizador on 24/05/2022.
//

