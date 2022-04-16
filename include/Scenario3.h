//
// Created by gonzallito on 16-04-2022.
//

#pragma once

#include <iostream>
#include <cmath>
#include "Courier.h"
#include "Data.h"
#include "Product.h"
#include <numeric>

using namespace std;

class Scenario3 {
private:
    vector<Product> products;
    vector<Courier> couriers;
public:
    Scenario3(const vector<Product> &products, const vector<Courier> &couriers);
    double getMinTime();
};