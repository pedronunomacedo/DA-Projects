//
// Created by gonzallito on 30-05-2022.
//

#include "Scenario1.h"

Scenario1::Scenario1() {}

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

void Scenario1::scenario1_2(vector<vector<tuple<int, int, int>>> &Graph, int source, int target) {

}


void Scenario1::bfs(int s, vector<vector<tuple<int, int, int>>> &Graph){
    // Mark all the vertices as not visited
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(50,false);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << "--";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: Graph[s])
        {
            if (!visited[get<1>(adjecent)])
            {
                visited[get<1>(adjecent)] = true;
                queue.push_back(get<1>(adjecent));
            }
        }
    }
}
