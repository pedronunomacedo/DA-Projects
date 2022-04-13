//
// Created by pedromacedo on 4/7/22.
//

#include <sstream>
#include "Data.h"
#include <string>


Data::Data() {

}

bool Data::readProducts(string filename) {
    fstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << "File " << filename << " doesn't exist\n";
        return false;
    }

    getline(file, line);
    while (getline(file, line)) {
        double volume, weight; int reward, duration;
        istringstream iss(line);
        iss >> volume >> weight >> reward >> duration;
        Product p(volume, weight, reward, duration);
        products.push_back(p);
    }
    file.close();
    return true;
}

bool Data::readCouriers(string filename) {
    fstream file(filename);
    string line;

    if (!file.is_open()) {
        cout << "File " << filename << " doesn't exist\n";
        return false;
    }

    getline(file, line);
    while (getline(file, line)) {
        //string name, plate;
        int maxVolume, maxWeight, cost;
        istringstream iss(line);
        iss >> maxVolume >> maxWeight >> cost;
        Courier c(maxVolume, maxWeight, cost);
        couriers.push_back(c);
    }
    file.close();
    return true;
}

const vector<Product> &Data::getProducts() {
    return products;
}

const vector<Courier> &Data::getTrucks() {
    return couriers;
}

