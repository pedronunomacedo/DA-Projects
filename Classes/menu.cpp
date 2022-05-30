#include <climits>
#include "menu.h"

// ---------------------------------------------------------------------------------------------------

menu::menu() {}
bool menu::pass() {
    if (cin.good())
        return true;
    else {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "\n Invalid input!\n";
        return false;
    }
}

void menu::mainMenu() const {
    cout << endl;
    cout << " ========================================" << endl;
    cout << " ||      Management of applications    ||" << endl;
    cout << " ||          for the transport of      ||" << endl;
    cout << " ||            groups of people        ||" << endl;
    cout << " ========================================" << endl;
    cout << endl;

    cout << " Choose an option:" << endl;
    cout << " [1] Referral from a group that does not part" << endl;
    cout << " [2] Referral from a group that is going to part" << endl;
    cout << " [0] Exit" << endl;
    cout << endl;
}
void menu::run() {
    while (true) {
        mainMenu();
        cout << " >";

        int option;
        cin >> option;

        if (pass()) {
            if (option == 1){}

            else if (option == 2){}

            else if (option == 0)
                exit(1);
            else
                cout << "\n Invalid input!\n";
        }
    }
}

