#include <iostream>
#include "Classes/menu.h"
#include "Classes/graph.h"
#include "Classes/Data.h"
#include "Classes/Scenario1.h"
#include <vector>
using namespace std;

int main() {

    Scenario1 scenario1;
    vector<Bus> buses;
    Data data;
    data.readProducts("../files/Tests_B/in01_b.txt");
    buses = data.getBuses();

    vector<vector<tuple<int, int, int> > > graph;

    int no_vertices = 50;

    graph.assign(no_vertices + 1, vector<tuple<int, int, int> >());

    for (auto & bus : buses) {
        graph[bus.src].push_back(make_tuple(bus.capacity, bus.dest, bus.duration));
    }

    cout << scenario1.widest_path_problem(graph, 1, 50);

    return 0;
}