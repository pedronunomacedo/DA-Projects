//
// Created by Utilizador on 30/05/2022.
//

#include "Data.h"
#include "graph.h"

Data::Data() {

}

bool Data::readProducts(string filename) {
    fstream file(filename);
    string line;
    int id = 0;

    if (!file.is_open()) {
        cout << "File " << filename << " doesn't exist\n";
        return false;
    }

    getline(file, line);
    while (getline(file, line)) {
        id++;
        int source, target, capacity, duration;
        istringstream iss(line);
        iss >> source >> target >> capacity >> duration;
        Bus p{source, target, capacity, duration};
        buses.push_back(p);
    }
    file.close();
    return true;
}

const vector<Bus> &Data::getBuses() {
    return buses;
}
