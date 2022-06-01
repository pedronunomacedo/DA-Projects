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
    // To keep track of widest distance
    vector<int> widest(Graph.size(), INT_MIN);

    // To get the path at the end of the algorithm
    vector<int> parent(Graph.size(), 0);

    // Use of Minimum Priority Queue to keep track minimum
    // widest distance vertex so far in the algorithm
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater< > > container;

    container.push(make_pair(0, src));

    widest[src] = INT_MAX;

    while (!container.empty()) {
        pair<int, int> temp = container.top();

        int current_src = temp.second;

        container.pop();

        for (auto vertex : Graph[current_src]) {

            // Finding the widest distance to the vertex
            // using current_source vertex's widest distance
            // and its widest distance so far
            int distance = max(widest[get<1>(vertex)],
                               min(widest[current_src], get<0>(vertex)));

            // Relaxation of edge and adding into Priority Queue
            if (distance > widest[get<1>(vertex)]) {

                // Updating bottle-neck distance
                widest[get<1>(vertex)] = distance;

                // To keep track of parent
                parent[get<1>(vertex)] = current_src;

                // Adding the relaxed edge in the priority queue
                container.push(make_pair(distance, get<1>(vertex)));
            }
        }
    }

    printpath(parent, target, target);

    return widest[target];
}
