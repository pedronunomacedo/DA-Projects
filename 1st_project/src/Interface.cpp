#include "../include/Interface.h"
#include <climits>

Interface::Interface() {
    couriers.clear();
    products.clear();
}

/**
 * Run the main menu and asks the user for an option
 */
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

/**
 * Function to check if the user input is a valid input or not
 * @return true if it's a valid input and false, otherwise
 */
bool Interface::pass() {
    if (cin.good()) return true;
    else {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\n Invalid input!\n";
        return false;
    }
}

/**
 * Run the main menu and goes to the function that the user choose
 */
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

/**
 * Asks for the user what scenario he wants to see from 3 different scenarios
 */

void Interface::scenariosMenu() const {
    cout << endl;
    cout << " Choose one of the following Optimization Scenarios: " << endl;
    cout << " [1] Optimization of the number of couriers" << endl;
    cout << " [2] Optimization of the company's profit" << endl;
    cout << " [3] Optimization of express deliveries" << endl;
    cout << " [0] Back" << endl;
    cout << endl;
}

/**
 * Shows the products menu
 */
void Interface::productsMenu() const {
    cout << endl;
    cout << " Choose one option: " << endl;
    cout << " [1] Add Product" << endl;
    cout << " [2] Find Product" << endl;
    cout << " [3] Delete Product" << endl;
    cout << " [0] Back " << endl;
    cout << endl;
}

/**
 * Shows the couriers menu
 */
void Interface::couriersMenu() const{
    cout << endl;
    cout << " Choose one option: " << endl;
    cout << " [1] Add Courier" << endl;
    cout << " [2] See Courier" << endl;
    cout << " [3] Delete Courier" << endl;
    cout << " [0] Back " << endl;
    cout << endl;
}

/**
 * Depending on what scenario the user choose, he show the result of the chosen scenario.
 */
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

/**
 * Shows the product menu.
 */
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

/**
 * Shows the couriers menu
 */
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

/**
 * In this option of the courier menu, we can add a courier to the list of couriers
 */
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

/**
 * In this option of the courier menu, we can check if a product exists or not. Always return an object of Product (class).
 * @return
 */
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
                        if ((x.getWeight() == weight) && (x.getVolume() == volume) && (x.getReward() == reward) && (x.getDuration() == duration)) {
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

/**
 * In this option in the couriers menu, we can delete a courier by its parameters. Only deletes a courier, if the parameters inputed by the user correspond to some product in the products vector.
 */
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
}

/**
 * In this option in the courier menu, we can add a courier to the vector of couriers.
 */
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

/**
 * In this option of the couriers menu, we can see all couriers.
 */
void Interface::seeC() {
    cout << endl;
    cout << " [See Couriers]" << endl << endl;

    for (const auto &x: couriers)
        cout << x << endl;
}

/**
 * In this option of the courier menu, we can delete a courier by giving its parameters.
 */
void Interface::delC() {
    cout << endl;
    cout << " [Delete Courier]" << endl << endl;
    int maxWeight, cost, maxVolume;

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
                            return;
                        }
                    }
                    cout << endl << " The Courier doesn't exist." << endl;
                }
            }
        }
    }
}

/**
 * Update the files in every change that we make while the program is running.
 */
void Interface::updateFiles() {
    ofstream myFile("data/carrinhas.txt");

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

/**
 * When the program starts, we will need to read the files and save their content to use it later.
 */
void Interface::readFiles() {
    data.readCouriers("data/carrinhas.txt");
    data.readProducts("data/encomendas.txt");
    couriers = data.getTrucks();
    products = data.getProducts();
    scenario1 = Scenario1(products, couriers);
    scenario2 = Scenario2(products, couriers, scenario1);
    scenario3 = Scenario3(products, couriers);
}



