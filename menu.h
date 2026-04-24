#ifndef GAMESTOP_MENU_H
#define GAMESTOP_MENU_H
#include <iostream>
#include <fstream>
#include <vector>
#include "customer.h"
#include "videogame.h"
#include "console.h"
#include "bundle.h"
#include "merch.h"
#include "product.h"
class Menu {
private:
    std::vector<Product *> inventory;
    float funds;
    bool running;
    void displayMenu();
    void add_product();
    void customer_visit();
    void make_bundle();
    void save_inventory();
public:
    Menu();
    ~Menu();
    void run();
};
#endif //GAMESTOP_MENU_H