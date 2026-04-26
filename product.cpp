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
    if (stock_quantity == 0)
        throw std::runtime_error("Stock quantity is zero, cannot calculate price.");
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

void  Product::read(std::istream& is,bool file_read) {
    try {
        std::string stock_price;
        std::string stock_quantity;
        if (!file_read)
            std::cout << "Enter stock quantity: ";
        getline(is,stock_quantity);
        if (!file_read)
            std::cout << "Enter price: ";
        getline(is,stock_price);
        int stock_quant = std::stoi(stock_quantity);
        float price = std::stof(stock_price);
        this->stock_quantity= stock_quant;
        this->stock_price = price;
    }catch (std::invalid_argument& e) {
        std::cout<<"Invalid input"<<'\n';
    }
}
std::istream& operator>>(std::istream& is, Product& p) {
    p.read(is,false);
    return is;
}
std:: ostream& operator<<(std::ostream& os, Product &p) {
    p.display(os);
    return os;
}