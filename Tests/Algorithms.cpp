//
// Created by gonzallito on 11/04/22.
//

#include "Algorithms.h"

Algorithms::Algorithms(const vector<Product> &products, const vector<Courier> &couriers) : products(products),
                                                                                           couriers(couriers) {}

int Algorithms::getMinCouriers() {
    int res = 0;

    sort(products.end(), products.begin());

    sort(couriers.end(), couriers.begin());

    // Create an array to store remaining space in bins
    // there can be at most n bins
    int bin_rem[couriers.size()];

    // Place items one by one
    for (int i = 0; i < couriers.size(); i++) {
        // Find the first bin that can accommodate
        // weight[i]
        int j;
        for (j = 0; j < res; j++) {
            if (bin_rem[j] >= products[i].getWeight()) {
                bin_rem[j] = bin_rem[j] - products[i].getWeight();

                break;
            }
        }

        // If no bin could accommodate weight[i]
        if (j == res) {
            bin_rem[res] = couriers[i].getMaxWeight() - products[i].getWeight();
            res++;
        }

    }
    return res;
}

