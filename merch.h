//
// Created by Admin on 16/04/2026.
//

#ifndef GAMESTOP_MERCH_H
#define GAMESTOP_MERCH_H
#include <string>

#include "product.h"

class Merchandise : public Product {
private:
    std::string type;
    std::string game_origin;
public:
    Merchandise();
    Merchandise(std::string type, std::string game_origin,int stock_price,int stock_quantity);
    Merchandise(const Merchandise& merch);
    ~Merchandise();
    Merchandise& operator=(const Merchandise& merch);
    void display();
    friend std::istream& operator>>(std::istream& is, Merchandise& p);
};
#endif //GAMESTOP_MERCH_H