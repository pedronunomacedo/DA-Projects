#include "Product.h"
#include <string>

Product::Product() {}

Product::Product(double volume, double weight, int reward, int duration) : volume(volume),weight(weight),
reward(reward), duration(duration) {}


double Product::getWeight() const {
    return weight;
}

double Product::getVolume() const {
    return volume;
}

int Product::getReward() const {
    return reward;
}

int Product::getDuration() const {
    return duration;
}

ostream &operator<<(ostream &os, const Product &product) {
    os << "volume: " << product.getVolume() << " weight: " << product.getWeight() << " reward: " << product.getReward()
       << " duration: " << product.getDuration();
    return os;
}


bool Product::operator<(const Product &rhs) const {
    return volume*weight < rhs.volume*rhs.weight;
}

bool Product::operator==(const Product &rhs) const {
    return volume*weight < rhs.volume*rhs.weight;
}
