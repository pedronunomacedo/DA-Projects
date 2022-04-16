//
// Created by gonzallito on 16-04-2022.
//

#include "Scenario2.h"

Scenario2::Scenario2(const vector<Product> &products, const vector<Courier> &couriers) : products(products),
                                                                                        couriers(couriers){}

int Scenario2::getMaxProfit() {
    int totalCost = 0, totalReward = 0;
    for (unsigned int i = 0; i < getMinCouriers() - 1; i++) {
        totalCost += couriers[i].getCost();
    }
    for (int i = 0; i < products.size(); ++i) {
        totalReward += products[i].getReward();
    }
    return -totalCost + totalReward;
}