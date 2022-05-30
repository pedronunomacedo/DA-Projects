//
// Created by Utilizador on 30/05/2022.
//

#ifndef PROJECT2_DA_DATA_H
#define PROJECT2_DA_DATA_H
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "graph.h"

using namespace std;

class Data {

private:
    vector<Bus> buses;
public:
    Data();
    bool readProducts(string filename);
    const vector<Bus> &getBuses();

};


#endif //PROJECT2_DA_DATA_H
