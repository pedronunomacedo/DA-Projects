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
