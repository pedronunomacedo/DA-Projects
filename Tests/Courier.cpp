#include "Product.h"
#include "Courier.h"

Courier::Courier(int maxVolume, int maxWeight, int cost) {
    //this->name = name;
    //this->plate = plate;
    this->maxVolume = maxVolume;
    this->maxWeight = maxWeight;
    this->cost = cost;
    //copy(this->products.begin(), this->products.end(), back_inserter(products));
}

vector<Product> Courier::getProducts() const {
    return products;
}

void Courier::addProducts(Product &product) {
    products.push_back(product);
}

bool Courier::removeProduct(Product &product) {
    auto it = find(products.begin(), products.end(), product); // memory position of &product
    if (it == products.end()) return false; // If &product doesn't exist in the products vector
    products.erase(it); // If it exists, remove it

    return true;
}

double Courier::getMaxVolume() {
    return maxVolume;
}

double Courier::getMaxWeight() {
    return maxWeight;
}

string Courier::getName() {
    return name;
}

int Courier::getCost() {
    return cost;
}

string Courier::getPlate() {
    return plate;
}

bool Courier::operator<(const Courier &rhs) const {
    return maxVolume < rhs.maxVolume;
}

bool Courier::operator==(const Courier &rhs) const {
    return maxWeight < rhs.maxWeight;
}
