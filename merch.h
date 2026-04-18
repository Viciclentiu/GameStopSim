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
    Merchandise(std::string type, std::string game_origin);
    Merchandise(const Merchandise& merch);
    ~Merchandise();
    Merchandise& operator=(const Merchandise& merch);

};
#endif //GAMESTOP_MERCH_H