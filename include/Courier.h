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
    int maxVolume;
    int maxWeight;
    int cost;
    vector<Product> products;

public:
    Courier();
    Courier(int maxVolume, int maxWeight, int cost);
    int getMaxVolume() const;
    int getMaxWeight() const;
    int getCost() const;
    friend ostream &operator<<(ostream &os, const Courier &courier);
    bool operator<(const Courier &rhs) const;
    bool operator==(const Courier &rhs) const;
};

