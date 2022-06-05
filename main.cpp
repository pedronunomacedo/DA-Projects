#include <iostream>
#include "Classes/graph.h"
#include "Classes/Scenario2.h"
#include "Classes/Scenario1.h"
#include <vector>

using namespace std;




void add_edge(vector<int> adj[], int src, int dest)
{
    adj[src].push_back(dest);
}

bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{

    list<int> queue;

    bool visited[v];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visited[adj[u][i]]) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == dest)
                    return true;
            }
        }
    }

    return false;
}

void printShortestDistance(vector<int> adj[], int s,
                           int dest, int v)
{

    int pred[v], dist[v];

    if (!BFS(adj, s, dest, v, pred, dist)) {
        cout << "Given source and destination are not connected";
        return;
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << "--";
}
















int main() {



    //////////////////////////////////////////////7


    //Scenario 1.1


    Scenario1 scenario1(51);
    Scenario1 scenario12(51);
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


    //////////////////////////////////////////////////////////


    //Scenario 2.1

    vector<vector<int> > mygraph(graph.size() , vector<int> (graph.size()));

    for (int i = 0; i <= g.getNrStops(); i++) {
        for (int j = 0; j <= g.getNrStops(); j++) {
            mygraph[i][j] = 0;
        }
    }

    for (int s = 0; s < g.getNrStops(); s++) {
        list<Bus> adjacent = g.getStops()[s].adj;
        for (auto & it : adjacent) {
            mygraph[s][it.dest-1] = it.capacity;
        }

    }



    ////////////////////////////////////////////////////////////


    //Scenario 1.2

    int v = 51;

    vector<int> adj[v];

    for (auto bus3 : buses) {
        add_edge(adj, bus3.src, bus3.dest);
    }

    int source = 1, dest = 50;


    ///////////////////////////////////////////////////////////////


    Scenario2 scenario2;

    cout << endl << endl;
    cout << "1.1: " << scenario1.scenario1_1(graph, 1, 50) << endl << endl;
    cout << "1.2: The shortest path is: "; printShortestDistance(adj, source, dest, v); cout << endl << endl;
    cout << "2.1: "; scenario2.scenario2_1(mygraph, 1, 50); cout << endl;
    cout << "2.2: "; scenario2.scenario2_2(mygraph, 1, 50); cout << endl;
    cout << "2.3: " << scenario2.scenario2_3(mygraph, 1, 50) << endl;

    return 0;
}