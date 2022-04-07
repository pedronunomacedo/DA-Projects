//
// Created by Utilizador on 07/04/2022.
//

#ifndef UNTITLED_DATA_H
#define UNTITLED_DATA_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Product.h"
#include "Courier.h"
using namespace std;

class Data {
private:
    vector<Product> products;
    vector<Courier> trucks;
public:
    bool readProducts(string &fname);
    bool readTrucks(string &fname);
};


#endif //UNTITLED_DATA_H
