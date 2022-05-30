//
// Created by gonzallito on 30-05-2022.
//

#ifndef PROJECT2_DA_SCENARIO1_H
#define PROJECT2_DA_SCENARIO1_H


#include "graph.h"

class Scenario1 {
private:
    vector<Bus> buses;
public:
    Scenario1();
    void printpath(vector<int>& parent, int vertex, int target);
    int widest_path_problem(vector<vector<tuple<int, int, int> > >& Graph, int src, int target);
};


#endif //PROJECT2_DA_SCENARIO1_H
