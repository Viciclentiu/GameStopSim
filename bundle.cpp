#include "bundle.h"
#include <vector>
#include <iostream>
#include <algorithm>
Bundle::Bundle() :Videogame() ,Console() {
    this->discount = 0.0;
    this->days_available.push_back(0);

}

Bundle::Bundle(float discount, std::vector<int> &days_available, Videogame &game, Console &console): Videogame(game),Console(console) {
    this->discount = discount;
    for (int i=0;i<days_available.size();i++) {
        this->days_available.push_back(days_available[i]);
    }
}

Bundle::~Bundle() {}

Bundle::Bundle(const Bundle &obj) : Videogame(obj),Console(obj) {
    this->discount = obj.discount;
    for (int i=0;i<obj.days_available.size();i++) {
        this->days_available.push_back(obj.days_available[i]);
    }
}
Bundle& Bundle::operator=(const Bundle& obj) {
    if (this == &obj) {
        return *this;
    }
    Videogame::operator=(obj);
    Console::operator=(obj);
    this->discount = obj.discount;
    for (int i=0;i<obj.days_available.size();i++) {
        this->days_available.push_back(obj.days_available[i]);
    }
    return *this;
}

void Bundle::display() {
    std::cout<<this->discount<<'\n';
    std::cout<<"Available days:"<<'\n';
    for (int i=0;i<this->days_available.size();i++) {
        std::cout<<this->days_available[i]<<'\n';
    }
}
float Bundle::price_discount() {
    return (this->get_price_per_product()+this->get_price_per_product()*discount);
}

int Bundle::get_last_day_available() {
    sort(this->days_available.begin(),this->days_available.end());
    return this->days_available.back();
}
std::istream& operator>>(std::istream& is,Bundle& obj) {
    std::cout<<"Enter the discount:"<<'\n';
    float discount;
    is>>discount;
    obj.discount = discount;
    std::cout<<"Enter the days available:"<<'\n';
    int days_available;
    is>>days_available;
    for (int i=0;i<days_available;i++) {
        int day;
        is>>day;
        obj.days_available.push_back(day);
    }
    is>>(Videogame&) obj;
    is>>(Console&) obj;
    return is;
}