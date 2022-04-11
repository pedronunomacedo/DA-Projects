//
// Created by Utilizador on 05/04/2022.
//

#ifndef UNTITLED_COURIER_H
#define UNTITLED_COURIER_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Product.h"
#include <string>
#include <vector>

using namespace std;

class Courier {
private:
    //string name;
    //string plate;
    int maxVolume;
    int maxWeight;
    int cost;
    vector<Product> products;

public:
    Courier(int maxVolume, int maxWeight, int cost);
    vector<Product> getProducts() const;
    void addProducts(Product &product);
    bool removeProduct(Product &product);
    double getMaxVolume();
    double getMaxWeight();
    string getName();
    int getCost();
    string getPlate();
    bool operator<(const Courier &rhs) const;
    bool operator==(const Courier &rhs) const;
};


#endif //UNTITLED_COURIER_H
