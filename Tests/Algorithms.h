//
// Created by gonzallito on 11/04/22.
//

#ifndef UNTITLED_ALGORITHMS_H
#define UNTITLED_ALGORITHMS_H

#include <iostream>
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
};


#endif //UNTITLED_ALGORITHMS_H
