
#include "graph.h"
#include <bits/stdc++.h>
#include <queue>
using namespace std;
Graph::Graph() {
    nr_stops = 0;
    stops.clear();
}

Graph::Graph(int num, bool stops) : nr_stops(num), stops(num + 1) {}


void Graph::addBus(int src, int dest, int capacity, int duration) {
    if (src < 1 || src > nr_stops || dest < 1 || dest > nr_stops || capacity < 1 || capacity > nr_stops || duration < 1 || duration > nr_stops )
        return;
    cout << "ola";
    stops[src].adj.push_back({dest,capacity,duration});

}


int Graph::getNrStops() const {
    return nr_stops;
}

int Graph::getNrBuses() const {
    return nr_buses;
}

void Graph::setNrStops(int num_stops) {
    nr_stops = num_stops;
}

void Graph::setNrBuses(int num_buses) {
    nr_buses = num_buses;
}
