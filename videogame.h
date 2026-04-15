
#ifndef GAMESTOP_VIDEOGAME_H
#define GAMESTOP_VIDEOGAME_H
#include "product.h"
#include <string>
class Videogame : public virtual Product {
protected:
    std::string name;
    std::string genre;
    std::string* compatible_consoles;
public:
    Videogame();
    Videogame(std::string name,std::string genre,std::string* compatible_consoles,int stock_price, int stock_quantity);
    virtual ~Videogame();
    Videogame &operator=(const Videogame &);
    Videogame(const Videogame& obj);
    void display() override;
};
#endif //GAMESTOP_VIDEOGAME_H