#include "Product.h"
#include <string>

Product::Product(double weight, double volume, int reward, int duration) : weight(weight), volume(volume),
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

void Product::setWeight(double weight) {
    Product::weight = weight;
}

void Product::setVolume(double volume) {
    Product::volume = volume;
}

void Product::setReward(int reward) {
    Product::reward = reward;
}

void Product::setDuration(int duration) {
    Product::duration = duration;
}

ostream &operator<<(ostream &os, const Product &product) {
    os << "weight: " << product.getWeight() << " volume: " << product.getVolume() << " reward: " << product.getReward()
       << " duration: " << product.getDuration();
    return os;
}


bool Product::operator<(const Product &rhs) const {
    return volume < rhs.volume;
}

bool Product::operator==(const Product &rhs) const {
    return weight < rhs.weight;
}
