//
// Created by pedromacedo on 4/7/22.
//

#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Product.h"
#include "Courier.h"
using namespace std;

class Data {
private:
    vector<Product> products;
    vector<Courier> couriers;
public:
    Data();
    bool readProducts(string filename);
    bool readCouriers(string filename);
    const vector<Product> &getProducts();
    const vector<Courier> &getTrucks();
};


#endif //UNTITLED_DATA_H
