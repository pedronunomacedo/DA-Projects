#include <iostream>
#include "Classes/menu.h"
#include "Classes/graph.h"
#include <vector>
using namespace std;

int main() {

    // Graph representation
    Graph graph1;
    vector<vector<pair<int, int> > > graph;

    graph.assign(graph1.getNodes().size() + 1, vector<pair<int, int> >());

    // Adding edges to graph

    // Resulting graph
    // 1--2
    // |  |
    // 4--3
    // Note that order in pair is (distance, vertex)
    graph1.addBus(1,2,4,6);
    graph1.addBus(2,3,3,5);
    graph1.addBus(3,4,3,7);
    graph1.addBus(4,1,3,7);

    cout << graph1.widest_path_problem(1, 4);
    return 0;
}
