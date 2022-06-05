//
// Created by Utilizador on 24/05/2022.
//

#ifndef PROJECT2_DA_MENU_H
#define PROJECT2_DA_MENU_H
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include "Scenario1.h"
#include "Scenario2.h"

using namespace std;

class Menu {
private:
    vector<Bus> buses;
    Graph g;
    vector<vector<tuple<int, int, int> > > graph;
    int no_vertices;
    Scenario1 scenario1;
    Scenario2 scenario2;
public:
    Menu();
    void run();
    void add_edge(vector<int> adj[], int src, int dest);
    void showMenuScenario1();
    void showMenuScenario2();
    void mainMenu() const;
    bool pass();
};
#endif //PROJECT2_DA_MENU_H
