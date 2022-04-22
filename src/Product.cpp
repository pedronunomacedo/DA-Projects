#include "Product.h"
#include <string>

Product::Product() {}

Product::Product(double volume, double weight, int reward, int duration) : volume(volume),weight(weight),
reward(reward), duration(duration) {}

/**
 * Sends the weight of the product
 * @return product weight
 */
double Product::getWeight() const {
    return weight;
}

/**
 * Sends the volume of the product
 * @return product volume
 */
double Product::getVolume() const {
    return volume;
}

/**
 * Sends the reward given to deliver the product
 * @return reward
 */
int Product::getReward() const {
    return reward;
}

/**
 * Sends the time that takes to deliver the product
 * @return (product deliver time)
 */
int Product::getDuration() const {
    return duration;
}

/**
 * Shows the information of a given product.
 * @param os
 * @param product (product to be shown)
 * @return os
 */
ostream &operator<<(ostream &os, const Product &product) {
    os << "volume: " << product.getVolume() << " weight: " << product.getWeight() << " reward: " << product.getReward()
       << " duration: " << product.getDuration();
    return os;
}

/**
 * Compares to products. First by their volume. And if equal, compares their weight.
 * @param rhs (second product to be in the comparison)
 * @return true if the first product has less weight then the second, or if equal weight if the first has less volume then the second.
 */
bool Product::operator<(const Product &rhs) const {
    return volume*weight < rhs.volume*rhs.weight;
}

bool Product::operator==(const Product &rhs) const {
    return volume*weight < rhs.volume*rhs.weight;
}
