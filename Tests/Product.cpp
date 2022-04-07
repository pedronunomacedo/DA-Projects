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
    os << "weight: " << product.weight << " volume: " << product.volume << " reward: " << product.reward
       << " duration: " << product.duration;
    return os;
}

void Product::readFile(string fname) {


}

bool Product::readFile(string &f) {
    string line;
    ifstream file(fname);
    getline(file, line);
    while(getline(file, line)) {
        istringstream iss(line);
        iss >> volume >> weight >> reward >> duration;
        Product p(weight, volume, reward, duration);

    }
    return false;
}
