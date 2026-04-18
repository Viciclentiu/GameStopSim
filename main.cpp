#include <iostream>

#include "videogame.h"
#include "console.h"
#include "bundle.h"
#include "merch.h"
#include "product.h"
int Product::product_no =0;
Product::Product() : product_id(++product_no) {
    this->stock_price = 0;
    this->stock_quantity = 0;
}

Product::Product(int stock_price, int stock_quantity): product_id(++product_no) {
    this->stock_price = stock_price;
    this->stock_quantity = stock_quantity;
}
Product::Product(const Product& obj): product_id(++product_no) {
    this->stock_price = obj.stock_price;
    this->stock_quantity = obj.stock_quantity;
}
Product:: ~Product(){}
Product& Product::operator=(const Product& obj) {
    this->stock_price = obj.stock_price;
    this->stock_quantity = obj.stock_quantity;
    return *this;
}
float Product::get_price_per_product() {
    return stock_price * stock_quantity;
}
Videogame::Videogame() : Product() {
    name="";
    genre="";

}
Videogame::Videogame(std::string name,std::string genre,std::vector<std::string >& compatible_consoles,int stock_price, int stock_quantity):Product(stock_price,stock_quantity) {
    this->name = name;
    this->genre = genre;
    for (int i=0;i<compatible_consoles.size();i++) {
        this->compatible_consoles.push_back(compatible_consoles[i]);
    }

}
Videogame::Videogame(const Videogame& obj) : Product(obj) {
    this->name=obj.name;
    this->genre = genre;
    for (int i=0;i<compatible_consoles.size();i++) {
        this->compatible_consoles.push_back(obj.compatible_consoles[i]);
    }
}
Videogame& Videogame::operator=(const Videogame& obj) {
    if (this == &obj) {
        return *this;
    }
    this->name=obj.name;
    this->genre = genre;
    this->compatible_consoles.clear();
    for (int i=0;i<compatible_consoles.size();i++) {
        this->compatible_consoles.push_back(obj.compatible_consoles[i]);
    }
    return *this;
}
void Videogame::display() {
    std::cout<<this->name<<'\n';
    std::cout<<this->genre<<'\n';
    std::cout<<"Compatible consoles:\n";
    for (int i=0;i<this->compatible_consoles.size();i++) {
        std::cout<<this->compatible_consoles[i];
    }
}
int main() {
    std::cout<<"Wlcome to GameStop";
    return 0;
}