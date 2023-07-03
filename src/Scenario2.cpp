//
// Created by gonzallito on 16-04-2022.
//

#include "Scenario2.h"

Scenario2::Scenario2() {

}

Scenario2::Scenario2(const vector<Product> &products, const vector<Courier> &couriers, Scenario1 a) : products(products),
                                                                                                      couriers(couriers),
                                                                                                      a(a) {}

/**
* Calculates the maximum possible profit that the company can achieve.
* @return (max possible profit)
*/
int Scenario2::getMaxProfit() {
    int totalCost = 0, totalReward = 0;
    for (unsigned int i = 0; i < a.getMinCouriers() - 1; i++) {
        totalCost += couriers[i].getCost();
    }
    for (auto & product : products) {
        totalReward += product.getReward();
    }
    return -totalCost + totalReward;
}
