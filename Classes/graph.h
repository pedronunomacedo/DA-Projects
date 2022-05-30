//
// Created by Utilizador on 24/05/2022.
//

#ifndef PROJECT2_DA_GRAPH_H
#define PROJECT2_DA_GRAPH_H

#include <list>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cfloat>
#include <climits>
#include <queue>
using namespace std;

class Graph {
    struct Edge {
        int dest;
        string lineCode;
    };

    struct Node {
        list<Edge> adj;
        double dist;
        int pred;
        bool visited;
    };

    int n;
    bool hasDir;
    vector<Node> nodes;

    void bfs(int s);
public:
    Graph();
    explicit Graph(int nodes, bool dir = false);
    int widest_path_problem(vector<vector<pair<int, int> > > &Graph, int src, int target);
    void addEdge(const pair<int,string> &src, const pair<int,string> &dest, const string &lineCode);
    void printpath(vector<int>& parent, int vertex, int target);
    vector<Node> getNodes() { return nodes; };
};

#endif //PROJECT2_DA_GRAPH_H
