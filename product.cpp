#include "product.h"
#include <iostream>
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
    if (this == &obj) {
        return *this;
    }
    this->stock_price = obj.stock_price;
    this->stock_quantity = obj.stock_quantity;
    return *this;
}
float Product::get_price_per_product() {
    return stock_price / stock_quantity;
}
void Product::set_stock_quantity(int quantity) {
    float price = this->get_price_per_product();
    this->stock_quantity = quantity;
    this->stock_price= price * quantity;
}
void Product::reduce_stock(int amount) {
    float initial_price = this->get_price_per_product();
    this->stock_quantity -= amount;
    this->stock_price = initial_price * this->stock_quantity;

}
int Product::get_stock_quantity() {
    return this->stock_quantity;
}
void Product::set_stock_price(float stock_price) {
    this->stock_price = stock_price;
}


std::istream& operator>>(std::istream& is, Product& p) {
    float stock_price;
    int stock_quantity;
    std::cout << "Enter stock quantity: ";
    is >> stock_quantity;
    std::cout << "Enter price: ";
    is >> stock_price;
    p.stock_quantity= stock_quantity;
    p.stock_price = stock_price;

    return is;
}