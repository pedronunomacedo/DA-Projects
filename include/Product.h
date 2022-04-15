//
// Created by Utilizador on 05/04/2022.
//

#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Product {
private:
    double weight;
    double volume;
    int reward;
    int duration;
public:
    Product();

    Product(double volume, double weight, int reward, int duration);

    double getWeight() const;

    double getVolume() const;

    int getReward() const;

    int getDuration() const;

    void setWeight(double weight);

    void setVolume(double volume);

    void setReward(int reward);

    void setDuration(int duration);

    friend ostream &operator<<(ostream &os, const Product &product);

    bool operator<(const Product &rhs) const;

    bool operator==(const Product &rhs) const;
};

