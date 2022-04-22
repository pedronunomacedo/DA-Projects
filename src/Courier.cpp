#include "Product.h"
#include "Courier.h"

Courier::Courier(int maxVolume, int maxWeight, int cost) {
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
    this->cost = cost;
}

int Courier::getMaxVolume() const {
    return maxVolume;
}

int Courier::getMaxWeight() const {
    return maxWeight;
}

int Courier::getCost() const {
    return cost;
}

bool Courier::operator<(const Courier &rhs) const {
    return maxVolume*maxWeight < rhs.maxVolume*rhs.maxWeight;
}

bool Courier::operator==(const Courier &rhs) const {
    return maxVolume*maxWeight < rhs.maxVolume*rhs.maxWeight;
}

Courier::Courier() {}

ostream &operator<<(ostream &os, const Courier &courier) {
    os << "volMax: " << courier.getMaxVolume() << " pesoMax: " << courier.getMaxWeight() << " custo: " << courier.getCost();
    return os;
}

