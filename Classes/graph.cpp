
#include "graph.h"
#include <bits/stdc++.h>
#include <queue>
using namespace std;
Graph::Graph() {
    nr_stops = 0;
    stops.clear();
}

Graph::Graph(int num, bool stops) : nr_stops(num), stops(num + 1) {}

// ---------------------------------------------------------------------------------------------------

void Graph::bfs(int s) {
    for (int v = 1; v <= nr_stops; v++)
        stops[v]. visited = false;

    queue<int> q;
    q.push(s);
    stops[s].visited = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto &e : stops[u].adj) {
            int w = e.dest;
            if (!stops[w].visited) {
                q.push(w);
                stops[w].visited = true;
                stops[w].pred = u;
            }
        }
    }
}

// ---------------------------------------------------------------------------------------------------

void Graph::addBus(int src, int dest, int capacity, int duration) {
    if (src < 1 || src > nr_stops || dest < 1 || dest > nr_stops || capacity < 1 || capacity > nr_stops || duration < 1 || duration > nr_stops )
        return;
    cout << "ola";
    stops[src].adj.push_back({dest,capacity,duration});

}

int Graph::widest_path_problem(int src, int target)
{
    // To keep track of widest distance
    vector<int> widest(getNodes().size(), INT_MIN);
    cout << getNodes().size();
    // To get the path at the end of the algorithm
    vector<int> parent(getNodes().size(), 0);

    // Use of Minimum Priority Queue to keep track minimum
    // widest distance vertex so far in the algorithm
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater< > > container;

    container.push(make_pair(0, src));

    widest[src] = INT_MAX;

    while (!container.empty()) {
        pair<int, int> temp = container.top();

        int current_src = temp.second;

        container.pop();
        cout << getNodes().size();
        for (auto bus : getNodes()[current_src].adj) {

            // Finding the widest distance to the vertex
            // using current_source vertex's widest distance
            // and its widest distance so far
            int distance = max(widest[bus.dest],
                               min(widest[current_src], bus.capacity));

            // Relaxation of edge and adding into Priority Queue
            if (distance > widest[bus.dest]) {

                // Updating bottle-neck distance
                widest[bus.dest] = distance;

                // To keep track of parent
                parent[bus.dest] = current_src;

                // Adding the relaxed edge in the priority queue
                container.push(make_pair(distance, bus.dest));
            }
        }
    }

    printpath(parent, target, target);

    return widest[target];
}

// ---------------------------------------------------------------------------------------------------
void Graph::printpath(vector<int> &parent, int vertex, int target)
{
    if (vertex == 0) {
        return;
    }

    printpath(parent, parent[vertex], target);

    cout << vertex << (vertex == target ? "\n" : "--");
}

// Function to print the required path


// Driver code

