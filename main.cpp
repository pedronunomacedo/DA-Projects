#include <iostream>
#include "Classes/menu.h"
#include "Classes/graph.h"
using namespace std;

void printpath(vector<int>& parent, int vertex, int target)
{
    if (vertex == 0) {
        return;
    }

    printpath(parent, parent[vertex], target);

    cout << vertex << (vertex == target ? "\n" : "--");
}

// Function to return the maximum weight
// in the widest path of the given graph

int widest_path_problem(vector<vector<pair<int, int> > >& Graph, int src, int target)
{
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
            int distance = max(widest[vertex.second],
                               min(widest[current_src], vertex.first));

            // Relaxation of edge and adding into Priority Queue
            if (distance > widest[vertex.second]) {

                // Updating bottle-neck distance
                widest[vertex.second] = distance;

                // To keep track of parent
                parent[vertex.second] = current_src;

                // Adding the relaxed edge in the priority queue
                container.push(make_pair(distance, vertex.second));
            }
        }
    }

    printpath(parent, target, target);

    return widest[target];
}

int main() {

    // Graph representation
    vector<vector<pair<int, int> > > graph;

    int no_vertices = 4;

    graph.assign(no_vertices + 1, vector<pair<int, int> >());

    // Adding edges to graph

    // Resulting graph
    // 1--2
    // |  |
    // 4--3

    // Note that order in pair is (distance, vertex)
    graph[1].push_back(make_pair(1, 2));
    graph[1].push_back(make_pair(2, 4));
    graph[2].push_back(make_pair(3, 3));
    graph[4].push_back(make_pair(5, 3));


    cout << widest_path_problem(graph, 1, 3);
    return 0;
}
