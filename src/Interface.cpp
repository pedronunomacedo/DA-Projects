#include "Interface.h"
#include <climits>
Interface::Interface() {
    couriers.clear();
    products.clear();
}

void Interface::mainMenu() const {
    cout << endl;
    cout << " ===============================" << endl;
    cout << "           Delivery             " << endl;
    cout << "       Data Management          " << endl;
    cout << " ===============================" << endl;
    cout << endl;

    cout << " Choose one option: " << endl;
    cout << " [1] Optimization Scenarios" << endl;
    cout << " [2] Products" << endl;
    cout << " [3] Couriers" << endl;
    cout << " [0] Exit" << endl;
    cout << endl;
}

bool Interface::pass() {
    if (cin.good()) return true;
    else {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\n Invalid input!\n";
        return false;
    }
}
void Interface::runMain() {
    readFiles();
    while (true) {
        mainMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            switch (option) {
                case 1:
                    runScenarios();
                    break;
                case 2:
                    runProducts();
                    break;
                case 3:
                    runCouriers();
                    break;
                case 0:
                    exit(1);
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}

void Interface::scenariosMenu() const {
    cout << endl;
    cout << " Choose one of the following Optimization Scenarios: " << endl;
    cout << " [1] Optimization of the number of couriers" << endl;
    cout << " [2] Optimization of the company's profit" << endl;
    cout << " [3] Optimization of express deliveries" << endl;
    cout << " [0] Back" << endl;
    cout << endl;
}

void Interface::productsMenu() const {
    cout << endl;
    cout << " Choose one option: " << endl;
    cout << " [1] Add Product" << endl;
    cout << " [2] Find Product" << endl;
    cout << " [3] Delete Product" << endl;
    cout << " [0] Back " << endl;
    cout << endl;
}

void Interface::couriersMenu() const{
    cout << endl;
    cout << " Choose one option: " << endl;
    cout << " [1] Add Courier" << endl;
    cout << " [2] See Courier" << endl;
    cout << " [3] Delete Courier" << endl;
    cout << " [0] Back " << endl;
    cout << endl;
}

void Interface::runScenarios() {
    bool running = true;
    while (running) {
        scenariosMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            switch (option) {
                case 1:
                    cout << " Min Couriers: " << scenario1.getMinCouriers() << endl;
                    break;
                case 2:
                    cout << " Max profit: " << scenario2.getMaxProfit() << endl;
                    break;
                case 3:
                    cout << " Mid Time: " << scenario3.getMidTime() << endl;
                    break;
                case 0:
                    running = false;
                    break;
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}

void Interface::runProducts() {
    bool running = true;
    while (running) {
        productsMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            switch (option) {
                case 1:
                    addP();
                    break;
                case 2:
                    seeP();
                    break;
                case 3:
                    delP();
                    break;
                case 0:
                    running = false;
                    break;
                default:
                    cout << "\n Invalid input!\n";
            }
            scenario1 = Scenario1(products, couriers);
            scenario2 = Scenario2(products, couriers, scenario1);
            scenario3 = Scenario3(products, couriers);
        }
    }
}

void Interface::runCouriers() {
    bool running = true;
    while (running) {
        couriersMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            switch (option) {
                case 1:
                    addC();
                    break;
                case 2:
                    seeC();
                    break;
                case 3:
                    delC();
                    break;
                case 0:
                    running = false;
                    break;
                default:
                    cout << "\n Invalid input!\n";
            }
            scenario1 = Scenario1(products, couriers);
            scenario2 = Scenario2(products, couriers, scenario1);
            scenario3 = Scenario3(products, couriers);
        }
    }
}

void Interface::addP() {
    cout << endl;
    cout << " [Add Product]" << endl;

    cout << endl;
    double weight, volume;
    int reward, duration;

     do {
        cout << " Volume:";
        cin >> volume;

        do {
            cout << " Weight:";
            cin >> weight;

            do {
                cout << " Reward:";
                cin >> reward;

                do {
                    cout << " Duration (seconds):";
                    cin >> duration;
                    cout << endl;
                } while (!pass());
            } while (!pass());
        } while (!pass());
    } while (!pass());
    Product p1(volume, weight, reward, duration);
    products.push_back(p1);
    updateFiles();
    cout << "We added it successfully! " << endl;
}

Product Interface::seeP() {
    cout << endl;
    double weight, volume;
    int reward, duration;

    if (pass()) {
        cout << " Volume:";
        cin >> volume;

        if (pass()) {
            cout << " Weight:";
            cin >> weight;

            if (pass()) {
                cout << " Reward:";
                cin >> reward;

                if (pass()) {
                    cout << " Duration (seconds):";
                    cin >> duration;
                    cout << endl;
                }

                if (pass()) {
                    for (const auto &x: products) {
                        if ((x.getWeight() == weight) && (x.getVolume() == volume) && (x.getReward() == reward) &&
                            (x.getDuration() == duration)) {
                            cout << "The product was found!" << endl;
                            return x;
                        }
                    }
                }
            }
        }
    }
    cout << "The product was not found! " << endl;
    Product p1(volume, weight, reward, duration);
    cout << endl;
    return p1;
}

void Interface::delP() {
    cout << endl;
    cout << " [Delete Product]" << endl;
    Product r = seeP();
    for (auto it = products.begin(); it != products.end(); it++) {
        if (r.getWeight() == (it)->getWeight() && r.getVolume() == it->getVolume() && r.getReward() == it->getReward() && r.getDuration() == it->getDuration()) {
            products.erase(it);
            updateFiles();
            cout << endl << " And deleted!" << endl;
            return;
        }
    }
    scenario1 = Scenario1(products, couriers);
    scenario2 = Scenario2(products, couriers, scenario1);
    scenario3 = Scenario3(products, couriers);
}

void Interface::addC() {
    cout << endl;
    int maxWeight, cost,maxVolume;

            if (pass()) {
                cout << " maxVolume:";
                cin >> maxVolume;

                if (pass()) {
                    cout << " maxWeight:";
                    cin >> maxWeight;

                    if (pass()) {
                        cout << " cost:";
                        cin >> cost;
                        cout << endl;
                    }
                }
            }
    Courier c(maxVolume,maxWeight,cost);
    cout << endl;
    couriers.push_back(c);
    updateFiles();
    scenario1 = Scenario1(products, couriers);
    scenario2 = Scenario2(products, couriers, scenario1);
    scenario3 = Scenario3(products, couriers);
    cout << "The courier was added!" << endl;

}

void Interface::seeC() {
    cout << endl;
    cout << " [See Couriers]" << endl << endl;

    for (const auto &x: couriers)
        cout << x << endl;
}

void Interface::delC() {
    cout << endl;
    cout << " [Delete Courier]" << endl << endl;
    int maxWeight, cost, maxVolume;
    bool found = false;

    if (pass()) {
        cout << " maxVolume:";
        cin >> maxVolume;

        if (pass()) {
            cout << " maxWeight:";
            cin >> maxWeight;

            if (pass()) {
                cout << " cost:";
                cin >> cost;

                if (pass()) {
                    for (auto it = couriers.begin(); it != couriers.end(); it++) {
                        if ((it->getCost() == cost) && (it->getMaxWeight() == maxWeight) && (it->getMaxVolume() == maxVolume)) {
                            couriers.erase(it);
                            updateFiles();
                            cout << endl << " The courier was deleted!" << endl;
                            found = true;
                            return;
                        }
                    }
                    if (!found) cout << endl << " The Courier doesn't exist." << endl;
                }
            }
        }
    }
}

void Interface::updateFiles() {
    ofstream myFile("../carrinhas.txt");

    for (Courier c : couriers) {
        myFile << c.getMaxVolume() << " " << c.getMaxWeight() << " " << c.getCost() << endl;
    }
    myFile.close();
    myFile.open("../encomendas.txt");

    for (Product p : products) {
        myFile << p.getVolume() << " " << p.getWeight() << " " << p.getReward() << " " << p.getDuration() << endl;
    }
    myFile.close();
}

void Interface::readFiles() {
    data.readCouriers("../carrinhas.txt");
    data.readProducts("../encomendas.txt");
    couriers = data.getTrucks();
    products = data.getProducts();
    scenario1 = Scenario1(products, couriers);
    scenario2 = Scenario2(products, couriers, scenario1);
    scenario3 = Scenario3(products, couriers);
}



