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

struct Bus {
    int src;
    int dest;
    int capacity;
    int duration;
};

struct Stop {
    list<Bus> adj;
    double dist;
    int pred;
    bool visited;
};


class Graph {
private:

    int nr_stops;
    vector<Stop> stops;

    void bfs(int s);
public:
    Graph();
    explicit Graph(int stops, bool dir = false);
    void addBus(int src, int dest, int capacity, int duration);
    vector<Stop> getNodes() { return stops; };
    int widest_path_problem(int src, int target);
    void printpath(vector<int> &parent, int vertex, int target);
};

#endif //PROJECT2_DA_GRAPH_H
