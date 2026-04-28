#include "bundle.h"
#include <vector>
#include <iostream>
#include <algorithm>
Bundle::Bundle() :Videogame() ,Console() {
    this->discount = 0.0;

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
    this->days_available.clear();
    for (int i=0;i<obj.days_available.size();i++) {
        this->days_available.push_back(obj.days_available[i]);
    }
    return *this;
}
void Bundle::serialize(std::ostream& os) {
    os<<"Bundle"<<'\n';
    os<<this->discount<<'\n';
    os<<this->days_available.size()<<'\n';
    for (int i=0;i<this->days_available.size();i++) {
        os<<this->days_available[i]<<'\n';
    }
    Videogame::serialize(os);
    Console::serialize(os);

}
void Bundle::display(std::ostream& cout) {
    cout<<"Bundle"<<'\n';
    cout<<this->discount<<"%"<<'\n';
    cout<<"Available days:"<<'\n';
    for (int i=0;i<this->days_available.size();i++) {
        cout<<this->days_available[i]<<'\n';
    }
    Videogame::display(cout);
    cout<<'\n';
    Console::display(cout);
    cout<<"Stock quantity:"<<'\n';
    cout<<this->stock_quantity<<'\n';
    cout<<"Stock Price:"<<'\n';
    cout<<this->stock_price<<'\n';
}
float Bundle::price_discount() {
    return (this->get_price_per_product()-this->get_price_per_product()*discount/100.0f);
}

int Bundle::get_last_day_available() {
    sort(this->days_available.begin(),this->days_available.end());
    return this->days_available.back();
}
void Bundle::read(std::istream& is,bool file_read) {
    try {
        std::string input;
        if (!file_read)
            std::cout << "Enter the discount:\n";
        getline(is,input);
        this->discount = std::stof(input);
        if (!file_read)
            std::cout << "Enter number of days available:\n";
        getline(is,input);
        int days = std::stoi(input);
        for (int i = 0; i < days; i++) {
            getline(is,input);
            int day = std::stoi(input);
            this->days_available.push_back(day);
        }
        Videogame::read(is,file_read);
        Console::read(is,file_read);
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid input!\n";
    }


}
std::istream& operator>>(std::istream& is,Bundle& obj) {
    obj.read(is,false);
    return is;
}
std::ostream& operator<<(std::ostream& cout, Bundle& obj) {
    obj.display(cout);
    return cout;
}
