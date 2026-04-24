#include "videogame.h"
#include <iostream>
Videogame::Videogame() : Product() {
    name="None";
    genre="None";

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
    this->genre = obj.genre;
    for (int i=0;i<obj.compatible_consoles.size();i++) {
        this->compatible_consoles.push_back(obj.compatible_consoles[i]);
    }
}

Videogame::~Videogame() {}

Videogame& Videogame::operator=(const Videogame& obj) {
    if (this == &obj) {
        return *this;
    }
    Product::operator=(obj);
    this->name=obj.name;
    this->genre = obj.genre;
    this->compatible_consoles.clear();
    for (int i=0;i<obj.compatible_consoles.size();i++) {
        this->compatible_consoles.push_back(obj.compatible_consoles[i]);
    }

    return *this;
}
void Videogame::display() {
    std::cout<<this->name<<'\n';
    std::cout<<this->genre<<'\n';
    std::cout<<"Compatible consoles:\n";
    for (int i=0;i<this->compatible_consoles.size();i++) {
        std::cout<<this->compatible_consoles[i]<<'\n';
    }
    std::cout<<"Price: $"<<this->get_price_per_product()<<'\n';
}
std::string Videogame::get_genre() {
    return this->genre;
}
std::istream& operator>>(std::istream& is,Videogame& obj) {
    std::string name,genre;

    std::cout<<"Enter video game name:\n";
    is>>name;
    std::cout<<"Enter genre:\n";
    is>>genre;
    std::cout<<"Enter compatible consoles:\n";
    obj.name=name;
    obj.genre=genre;
    int n;
    std::string console;
    is>>n;

    for (int i=0;i<n;i++) {
        is>>console;
        obj.compatible_consoles.push_back(console);
    };
    is>>(Product&) obj;

    return is;
}