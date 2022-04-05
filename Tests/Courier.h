//
// Created by Utilizador on 05/04/2022.
//

#ifndef UNTITLED_COURIER_H
#define UNTITLED_COURIER_H
#include <iostream>
#include <vector>
#include "Product.h"

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
    Courier(string name, string plate, int maxVolume, int maxWeight, int cost, vector<Product> products);
    vector<Product> getProducts() const;
    void addProducts();
    void removeProduct(Product &product);
    double getMaxVolume();
    double getMaxWeight();
    string getName();
    int getCost();
    string getPlate();

};


#endif //UNTITLED_COURIER_H
