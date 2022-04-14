#include "Interface.h"

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
    while (true) {
        mainMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            switch (option) {
                case 1:
                    cout << "oi";
                    break;
                case 2:
                    cout << "oi";
                    break;
                case 3:
                    cout << "oi";
                    break;
                case 4:
                    cout << "oi";
                    break;
                case 0:
                    exit(1);
                default:
                    cout << "\n Invalid input!\n";
            }
        }
    }
}

