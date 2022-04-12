#include <iostream>
#include "Courier.h"
#include "Product.h"
#include "Algorithms.h"

using namespace std;

int main(){
    Data data;
    data.readCouriers("../carrinhas.txt");
    data.readProducts("../encomendas.txt");

    Algorithms algorithms(data.getProducts(), data.getTrucks());

    cout << "Min Couriers: " << algorithms.getMinCouriers() << endl;

    return 0;
}
