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

    cout << "Min Couriers (1st cenario): " << algorithms.getMinCouriers() << endl;
    cout << "Mid Time (3nd cenario): " << algorithms.getMinTime() << endl;

    return 0;
}
