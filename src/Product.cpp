#include "Product.h"
#include <string>

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
    os << "volume: " << product.getVolume() << " weight: " << product.getWeight() << " reward: " << product.getReward()
       << " duration: " << product.getDuration();
    return os;
}


bool Product::operator<(const Product &rhs) const {
    if (volume == rhs.volume){
        return weight < rhs.weight;
    }
    return volume < rhs.volume;
}

bool Product::operator==(const Product &rhs) const {
    return weight < rhs.weight;
}

Product::Product() {}
