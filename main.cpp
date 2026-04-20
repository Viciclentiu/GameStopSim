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
        std::cout<<this->compatible_consoles[i];
    }
}
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
Merchandise& Merchandise::operator=(const Merchandise &obj) {
    if (this == &obj) {
        return *this;
    }
    Product::operator=(obj);
    this->type=obj.type;
    this->game_origin=obj.game_origin;

}

int main() {
    std::cout<<"Wlcome to GameStop";
    return 0;
}