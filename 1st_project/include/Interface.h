//
// Created by Utilizador on 13/04/2022.
//

#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Scenario1.h"
#include "Scenario2.h"
#include "Scenario3.h"
#include "Courier.h"
#include "Product.h"
#include "Data.h"


using namespace std;

class Interface {
private:
    vector<Product> products;
    vector<Courier> couriers;
    Data data;
    Scenario1 scenario1;
    Scenario2 scenario2;
    Scenario3 scenario3;
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
    void updateFiles();
    void readFiles();
};