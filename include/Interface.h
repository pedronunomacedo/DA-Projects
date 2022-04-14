//
// Created by Utilizador on 13/04/2022.
//

#pragma once

#include <iostream>
#include <fstream>
#include "Algorithms.h"
#include "Courier.h"
#include "Product.h"
#include "Data.h"
#include <vector>

using namespace std;

class Interface {
private:
    vector<Product> products;
    vector<Courier> couriers;
public:
    Interface();
    bool pass();
    void mainMenu() const;
    void runMain();
};