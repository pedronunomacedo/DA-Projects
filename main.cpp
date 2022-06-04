#include <iostream>
#include "Classes/graph.h"
#include "Classes/Scenario2.h"
#include "Classes/Scenario1.h"
#include <vector>

using namespace std;

int main() {

    Scenario1 scenario1;
    vector<Bus> buses;
    Graph g;
    g.readData("../files/Tests_B/in01_b.txt");
    buses = g.getBuses();

    vector<vector<tuple<int, int, int> > > graph;

    int no_vertices = g.getNrStops();

    graph.assign(no_vertices + 1, vector<tuple<int, int, int> >());

    for (auto & bus : buses) {
        graph[bus.src].push_back(make_tuple(bus.capacity, bus.dest, bus.duration));
    }


    //Scenario 2.1

    vector<vector<int> > mygraph(graph.size() , vector<int> (graph.size()));

    //memset(graph2, 0, 60 * 50);
    for (int i = 0; i <= g.getNrStops(); i++) {
        for (int j = 0; j <= g.getNrStops(); j++) {
            mygraph[i][j] = 0;
        }
    }

    for (int s = 0; s < g.getNrStops(); s++) {
        list<Bus> adjacent = g.getStops()[s].adj;
        for (auto & it : adjacent) {
            //graph2[s][it.dest] = it.capacity;
            mygraph[s][it.dest-1] = it.capacity;
        }

    }
    /*for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            cout << mygraph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;*/


    /*for (int i = 0; i < g.getNrStops(); ++i) {
        for (int j = 0; j < g.getNrStops(); ++j) {
            cout << graph2[i][j] << " ";
        }
        cout << endl;
    }*/

    Scenario2 scenario2;

    cout << endl << endl;
    cout << "1.1: " << scenario1.scenario1_1(graph, 1, 50) << endl << endl;
    cout << "2.1: "; scenario2.scenario2_1(mygraph, 1, 50); cout << endl;
    cout << "2.3: " << scenario2.scenario2_3(mygraph, 1, 50) << endl;

    return 0;
}