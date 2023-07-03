#include "Product.h"
#include "Courier.h"

Courier::Courier(int maxVolume, int maxWeight, int cost) {
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
    this->cost = cost;
}

/**
 *
 * @return Max volume of the courier truck
 */
int Courier::getMaxVolume() const {
    return maxVolume;
}

/**
 *
 * @return Max weight of the courier truck
 */
int Courier::getMaxWeight() const {
    return maxWeight;
}

/**
 *
 * @return Cost of the courier to transport his products
 */
int Courier::getCost() const {
    return cost;
}

/**
 * Compares two couriers. First by their max volume, and second by their weight (if volume is equal)
 * @param rhs (second product of the comparison)
 * @return The product that has less volume, or less weight (if volume of the both are equal)
 */
bool Courier::operator<(const Courier &rhs) const {
    return maxVolume*maxWeight < rhs.maxVolume*rhs.maxWeight;
}

bool Courier::operator==(const Courier &rhs) const {
    return maxVolume*maxWeight < rhs.maxVolume*rhs.maxWeight;
}

Courier::Courier() {}

/**
 * Prints the information of a courier
 * @param os
 * @param courier (courier to print the information)
 * @return os
 */
ostream &operator<<(ostream &os, const Courier &courier) {
    os << "volMax: " << courier.getMaxVolume() << " pesoMax: " << courier.getMaxWeight() << " custo: " << courier.getCost();
    return os;
}

