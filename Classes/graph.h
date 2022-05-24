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

    void addEdge(const pair<int,string> &src, const pair<int,string> &dest, const string &lineCode);


    vector<Node> getNodes() { return nodes; };
};



#endif //PROJECT2_DA_GRAPH_H
