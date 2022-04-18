//
// Created by gonzallito on 16-04-2022.
//

#pragma once

#include <iostream>
#include <cmath>
#include "Courier.h"
#include "Data.h"
#include "Product.h"

using namespace std;

class Scenario1 {
private:
    vector<Product> products;
    vector<Courier> couriers;
public:
    Scenario1();
    Scenario1(vector<Product> &products, vector<Courier> &couriers);
    int getMinCouriers();
};
