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
void Console::display(std::ostream& cout) {
    cout<<"Console"<<'\n';
    cout<<this->name<<'\n';
    cout<<this->description<<'\n';
    cout<<"Specifications:"<<'\n';
    for (int i =0; i<this->specs.size();i++) {
        cout<<this->specs[i]<<'\n';
    }
}
void Console::read(std::istream& is,bool file_read) {
    std::string name;
    std::string description;
    std::vector<std::string> specs;
    if (!file_read)
        std::cout<<"Name: ";
    is.get();
    getline(is,name);
    if (!file_read)
        std::cout<<"Description: ";
    getline(is,description);
    int n;
    if (!file_read)
        std::cout<<"Number of specs: ";
    is>>n;
    is.get();
    this->name = name;
    this->description = description;
    std::string spec;
    for (int i=0;i<n;i++) {
        if (!file_read)
            std::cout<<"Specs: ";
        getline(is,spec);
        this->specs.push_back(spec);
    }
    Product::read(is,file_read);

}
std::istream& operator>>(std::istream& is, Console& obj) {
   obj.read(is,false);
    return is;
}
std::ostream& operator<<(std::ostream& cout, Console& obj) {
    obj.display(cout);
    return cout;
}