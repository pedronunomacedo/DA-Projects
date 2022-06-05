//
// Created by gonzallito on 30-05-2022.
//

#ifndef PROJECT2_DA_SCENARIO1_H
#define PROJECT2_DA_SCENARIO1_H


#include "graph.h"

class Scenario1 {
private:
    vector<Bus> buses;
    vector<list<int>> adj;
    int V;
public:
    Scenario1(int V);
    void addEdge(int v, int w);
    void printpath(vector<int>& parent, int vertex, int target);
    int scenario1_1(vector<vector<tuple<int, int, int> > >& Graph, int src, int target);
    void bfs(int v);  //, int t, vector<vector<tuple<int, int, int>>> &Graph, vector<int> &parent
    vector<list<int>> getAdj() {return adj;}
};


#endif //PROJECT2_DA_SCENARIO1_H
