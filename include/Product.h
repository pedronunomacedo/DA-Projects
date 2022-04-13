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
    int id;
    double weight;
    double volume;
    int reward;
    int duration;
public:
    Product();

    Product(int id, double volume, double weight, int reward, int duration);

    int getId() const;

    double getWeight() const;

    double getVolume() const;

    int getReward() const;

    int getDuration() const;

    void setId(int id);

    void setWeight(double weight);

    void setVolume(double volume);

    void setReward(int reward);

    void setDuration(int duration);

    friend ostream &operator<<(ostream &os, const Product &product);

    bool operator<(const Product &rhs) const;

    bool operator==(const Product &rhs) const;
};

