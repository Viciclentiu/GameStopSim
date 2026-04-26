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
void Videogame::display(std::ostream& cout) {
    cout<<"Videogame"<<'\n';
    cout<<this->name<<'\n';
    cout<<this->genre<<'\n';
    cout<<"Compatible consoles:\n";
    for (int i=0;i<this->compatible_consoles.size();i++) {
        cout<<this->compatible_consoles[i]<<'\n';
    }
    cout<<this->stock_quantity<<'\n';
    cout<<"Price: $"<<this->get_price_per_product()<<'\n';
}
std::string Videogame::get_genre() {
    return this->genre;
}
void Videogame::read(std::istream& is,bool file_read) {
    std::string name,genre;
    if (!file_read)
        std::cout<<"Enter video game name:\n";
    is.get();
    getline(is,name);
    if (!file_read)
        std::cout<<"Enter genre:\n";
    is.get();
    getline(is,genre);
    this->name = name;
    this->genre = genre;
    if (!file_read)
        std::cout<<"Enter number of compatible consoles:\n";
    try {
        int n;
        std::string console;
        is>>n;
        is.get();
        for (int i=0;i<n;i++) {
            if (file_read)
                std::cout<<"Enter number of consoles:\n";
            getline(is,console);
            this->compatible_consoles.push_back(console);
        }
        Product::read(is,file_read);
    }catch(std::invalid_argument& e) {
        std::cout<<"Invalid input! Try again\n";
    }

}
std::istream& operator>>(std::istream& is,Videogame& obj) {
    obj.read(is,false);
    return is;
}
std::ostream& operator<<(std::ostream& cout,Videogame& obj) {
    obj.display(cout);
    return cout;
}