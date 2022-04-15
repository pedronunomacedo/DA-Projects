//
// Created by Utilizador on 05/04/2022.
//

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include "Product.h"
#include <string>
#include <vector>

using namespace std;

class Courier {
private:
    string name;
    string plate;
    int maxVolume;
    int maxWeight;
    int cost;
    vector<Product> products;

public:
    Courier();
    Courier(int maxVolume, int maxWeight, int cost);
    vector<Product> getProducts() const;
    void addProducts(Product &product);
    bool removeProduct(Product &product);

    int getMaxVolume() const;
    int getMaxWeight() const;
    string getName() const;
    int getCost() const;
    string getPlate() const;
    friend ostream &operator<<(ostream &os, const Courier &courier);
    bool operator<(const Courier &rhs) const;
    bool operator==(const Courier &rhs) const;
};

