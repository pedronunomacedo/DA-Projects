//
// Created by gonzallito on 16-04-2022.
//

#include "Scenario3.h"

Scenario3::Scenario3() {

}

Scenario3::Scenario3(const vector<Product> &products, const vector<Courier> &couriers) : products(products),
                                                                                         couriers(couriers) {}

bool durationLess(Product const &p1, Product const &p2){
    if (p1.getDuration() == p2.getDuration()) {
        return (p1.getReward() <= p2.getReward());
    }

    return p1.getDuration() < p2.getDuration();
}

double Scenario3::getMidTime() {
    int res = 0;
    vector<double> times;

    sort(products.begin(), products.end(), &durationLess);

    for (int i = 0; i < products.size() && res <= 28800; ++i) {
        res += products[i].getDuration();
        times.push_back(res);
    }

    return accumulate(times.begin(), times.end(), 0)/ times.size();
}
