//
// Created by gonzallito on 31-05-2022.
//

#ifndef PROJECT2_DA_SCENARIO2_H
#define PROJECT2_DA_SCENARIO2_H

#include <stdlib.h>
#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;


class Scenario2 {
private:
    int no_vertices; // Variable never used (DELETE)!
public:
    Scenario2();
    void setNrVertices(int v);
    void printPath(vector<int>& parent, int source, int target);
    bool bfs(vector<vector<int> > &rGraph, int s, int t, vector<int> &parent);
    void scenario2_1(vector<vector<int> > graph, int s, int t, int size);
    void scenario2_2(vector<vector<int> > graph, int s, int t, int size);
    void scenario2_3(vector<vector<int> > graph, int s, int t);
    void scenario2_4(vector<vector<int> > graph, int s, int t, int size);
    void scenario2_5(vector<vector<int> > graph, int s, int t);
};


#endif //PROJECT2_DA_SCENARIO2_H
