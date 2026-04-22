#include "console.h"
#include <iostream>
#include <vector>
Console::Console(): Product() {
    this->name="None";
    this->description="None";
    this->specs.push_back("None");

}

Console::Console(std::string name, std::string description, std::vector<std::string> specs, int stock_price, int stock_quantity):Product(stock_price,stock_quantity) {
    this->name = name;
    this->description = description;
    for (int i=0;i<specs.size();i++) {
        this->specs.push_back(specs[i]);
    }
}

Console::Console(const Console& obj) : Product(obj) {
    this->name = obj.name;
    this->description = obj.description;
    for (int i=0;i<obj.specs.size();i++) {
        this->specs.push_back(obj.specs[i]);
    }
}

Console::~Console() {}

Console& Console::operator=(const Console& obj) {
    if (this == &obj) {
        return *this;
    }
    Product::operator=(obj);
    this->name = obj.name;
    this->description = obj.description;
    for (int i=0;i<obj.specs.size();i++) {
        this->specs.push_back(obj.specs[i]);
    }
    return *this;
}
void Console::display() {
    std::cout<<this->name<<'\n';
    std::cout<<this->description<<'\n';
    std::cout<<"Specifications:"<<'\n';
    for (int i =0; this->specs.size();i++) {
        std::cout<<this->specs[i]<<'\n';
    }
}