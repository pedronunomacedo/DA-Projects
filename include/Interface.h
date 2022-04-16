//
// Created by Utilizador on 13/04/2022.
//

#pragma once

#include <iostream>
#include <fstream>
#include "Scenario1.h"
#include "Scenario3.h"
#include "Scenario3.h"
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
    void scenariosMenu() const;
    void productsMenu() const;
    void couriersMenu() const;
    void runScenarios();
    void runProducts();
    void runCouriers();
    void addP();
    Product seeP();
    void delP();
    void addC();
    void seeC();
    void delC();

};