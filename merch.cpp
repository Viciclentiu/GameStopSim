#include "merch.h"
Merchandise::Merchandise(): Product() {
    this->type="None";
    this->game_origin="None";
}

Merchandise::Merchandise(std::string type, std::string game_origin,int stock_price,int stock_quantity): Product(stock_price,stock_quantity) {
    this->type=type;
    this->game_origin=game_origin;
}

Merchandise::Merchandise(const Merchandise &merch):Product(merch) {
    this->type=merch.type;
    this->game_origin=merch.game_origin;
}

Merchandise::~Merchandise() {}

Merchandise& Merchandise::operator=(const Merchandise &obj) {
    if (this == &obj) {
        return *this;
    }
    Product::operator=(obj);
    this->type=obj.type;
    this->game_origin=obj.game_origin;
    return *this;
}
