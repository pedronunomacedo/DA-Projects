//
// Created by Utilizador on 24/05/2022.
//

#ifndef PROJECT2_DA_MENU_H
#define PROJECT2_DA_MENU_H
#include <vector>
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class menu {
    void mainMenu() const;
    bool pass();
public:
    menu();
    void run();
};
#endif //PROJECT2_DA_MENU_H
