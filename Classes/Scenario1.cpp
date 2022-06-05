//
// Created by gonzallito on 30-05-2022.
//

#include <cstring>
#include "Scenario1.h"

Scenario1::Scenario1(int V) {
    this->V = V;
    adj.resize(V);
}

void Scenario1::printpath(vector<int> &parent, int vertex, int target) {
    if (vertex == 0) {
        return;
    }

    printpath(parent, parent[vertex], target);

    cout << vertex << (vertex == target ? "\n" : "--");
}

int Scenario1::scenario1_1(vector<vector<tuple<int, int, int>>> &Graph, int src, int target) {
    vector<int> widest(Graph.size(), INT_MIN);

    vector<int> parent(Graph.size(), 0);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater< > > container;

    container.push(make_pair(0, src));

    widest[src] = INT_MAX;

    while (!container.empty()) {
        pair<int, int> temp = container.top();

        int current_src = temp.second;

        container.pop();

        for (auto vertex : Graph[current_src]) {

            int distance = max(widest[get<1>(vertex)],
                               min(widest[current_src], get<0>(vertex)));

            if (distance > widest[get<1>(vertex)]) {

                widest[get<1>(vertex)] = distance;

                parent[get<1>(vertex)] = current_src;

                container.push(make_pair(distance, get<1>(vertex)));
            }
        }
    }

    cout << "The path is: "; printpath(parent, target, target);
    cout << "     The maximum capacity is: ";
    return widest[target];
}


void Scenario1::bfs(int v){

/*
    vector<bool> visited;
    visited.resize(V,false);

    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        for (auto adjecent: adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }*/
    vector<bool> nodes(51, false);
    queue<int> q;
    q.push(v);
    nodes[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto e : adj[v]) {
            if (!nodes[e]) {
                q.push(e);
                nodes[e] = true;
            }
        }
    }
}

void Scenario1::addEdge(int v, int w) {
    adj[v].push_back(w);
}
