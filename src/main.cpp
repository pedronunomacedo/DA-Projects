
#include "Interface.h"
#include "Scenario1.h"
#include "Data.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]){
    //Interface UI;
    //UI.runMain();
    Data a;
    a.readProducts("../encomendas.txt");
    a.readCouriers("../carrinhas.txt");
    Scenario3 b(a.getProducts(), a.getTrucks());
    cout << b.getMinTime();
}
