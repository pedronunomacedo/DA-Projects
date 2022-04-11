#include <iostream>
#include "Tests/Courier.h"
#include "Tests/Product.h"
#include "Tests/Algorithms.h"
using namespace std;

int main(){
    Data data;
    data.readCouriers("carrinhas.txt");
    data.readProducts("encomendas.txt");

    Algorithms algorithms(data.getProducts(), data.getTrucks());
    int minCouriers = algorithms.getMinCouriers();

    cout << "Min Couriers: " << minCouriers << endl;
    return 0;
}
