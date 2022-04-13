//
// Created by gonzallito on 11/04/22.
//

#pragma once

#include <iostream>
#include <cmath>
#include "Courier.h"
#include "Data.h"
#include "Product.h"

using namespace std;

class Algorithms {
private:
    vector<Product> products;
    vector<Courier> couriers;
public:
    Algorithms(const vector<Product> &products, const vector<Courier> &couriers);
    int getMinCouriers();
    double getMinTime();
};

