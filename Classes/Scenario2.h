//
// Created by gonzallito on 31-05-2022.
//

#ifndef PROJECT2_DA_SCENARIO2_H
#define PROJECT2_DA_SCENARIO2_H

#define V 7
#include <vector>
using namespace std;


class Scenario2 {
private:

public:
    Scenario2();
    int Scenario2_1();
    int scenario2_2(vector<vector<int> > graph, int s, int t);
    bool bfs(vector<vector<int> > graph, int s, int t, int parent[]);
    int scenario2_3(vector<vector<int> > graph, int s, int t);
};


#endif //PROJECT2_DA_SCENARIO2_H
