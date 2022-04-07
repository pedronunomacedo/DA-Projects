//
// Created by Utilizador on 05/04/2022.
//

#ifndef UNTITLED_PRODUCTS_H
#define UNTITLED_PRODUCTS_H
#include <iostream>
using namespace std;

class Product {
private:
    double weight;
    double volume;
    int reward;
    int duration;
public:
    Product(double weight, double volume, int reward, int duration);

    double getWeight() const;

    double getVolume() const;

    int getReward() const;

    int getDuration() const;

    void setWeight(double weight);

    void setVolume(double volume);

    void setReward(int reward);

    void setDuration(int duration);

    friend ostream &operator<<(ostream &os, const Product &product);

    bool readFile(string &f);
};




#endif //UNTITLED_PRODUCTS_H
