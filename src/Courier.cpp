#include "Product.h"
#include "Courier.h"

Courier::Courier(int id, int maxVolume, int maxWeight, int cost) {
    //this->name = name;
    //this->plate = plate;
    this->id = id;
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

int Courier::getId() const {
    return id;
}

int Courier::getMaxVolume() const {
    return maxVolume;
}

int Courier::getMaxWeight() const {
    return maxWeight;
}

string Courier::getName() const {
    return name;
}

int Courier::getCost() const {
    return cost;
}

string Courier::getPlate() const {
    return plate;
}

bool Courier::operator<(const Courier &rhs) const {
    if (maxVolume == rhs.maxVolume)
        return maxWeight < rhs.maxWeight;
    return maxVolume < rhs.maxVolume;
}

bool Courier::operator==(const Courier &rhs) const {
    return maxWeight < rhs.maxWeight;
}

Courier::Courier() {}

ostream &operator<<(ostream &os, const Courier &courier) {
    os << "volMax: " << courier.getMaxVolume() << " pesoMax: " << courier.getMaxWeight() << " custo: " << courier.getCost();
    return os;
}

