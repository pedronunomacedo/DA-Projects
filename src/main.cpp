
#include "Interface.h"
#include "Scenario1.h"
#include "Scenario2.h"
#include "Scenario3.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
    Interface UI;
    UI.runMain();
    UI.updateFiles();
    /*Data a;
    a.readProducts("../encomendas.txt");
    a.readCouriers("../carrinhas.txt");
    Scenario1 b(a.getProducts(), a.getTrucks());
    Scenario2 c(a.getProducts(), a.getTrucks(), b);
    Scenario3 d(a.getProducts(), a.getTrucks());
    cout << "Min Couriers: " << b.getMinCouriers() << endl;
    cout << "Max Profit: " << c.getMaxProfit() << endl;
    cout << "Min Time: " << d.getMidTime() << endl;*/
}
