//
// Created by gonzallito on 11/04/22.
//

#include "Algorithms.h"

Algorithms::Algorithms(const vector<Product> &products, const vector<Courier> &couriers) : products(products),
                                                                                           couriers(couriers) {}

int Algorithms::getMinCouriers() {
    int res = 0;

    sort(products.rbegin(), products.rend());

    sort(couriers.rbegin(), couriers.rend());

    // Create an array to store remaining space in bins. There can be at most n bins
    int bin_rem[products.size()][2];

    // Place items one by one
    for (int i = 0; i < products.size(); i++) {
        // Find the first bin that can accommodate weight[i]
        int j;
        for (j = 0; j < res; j++) {
            if (bin_rem[j][0] >= products[i].getVolume() && bin_rem[j][1] >= products[i].getWeight()) {
                bin_rem[j][0] = bin_rem[j][0] - products[i].getVolume();
                bin_rem[j][1] = bin_rem[j][1] - products[i].getWeight();

                break;
            }
        }

        // If no bin could accommodate weight[i]
        if (j == res) {
            bin_rem[res][0] = couriers[res].getMaxVolume() - products[i].getVolume();
            bin_rem[res][1] = couriers[res].getMaxWeight() - products[i].getWeight();
            res++;
        }

    }
    return res;
}

