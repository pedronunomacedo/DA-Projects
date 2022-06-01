//
// Created by Utilizador on 30/05/2022.
//

#include "Data.h"
#include "graph.h"

Data::Data() {

}



bool Data::readData(Graph &g, string filename) {
    fstream file(filename);
    string firstline, line;
    int id = 0;

    if (!file.is_open()) {
        cout << "File " << filename << " doesn't exist\n";
        return false;
    }

    getline(file, firstline);
    int nr_stops, nr_buses;
    istringstream iss1(firstline);
    iss1 >> nr_stops >> nr_buses;
    g.setNrStops(nr_stops);
    g.setNrBuses(nr_buses);
    while (getline(file, line)) {
        id++;
        int source, target, capacity, duration;
        istringstream iss(line);
        iss >> source >> target >> capacity >> duration;
        Bus p{source, target, capacity, duration};
        g.addBus(source, target, capacity, duration);
    }
    file.close();
    return true;
}
