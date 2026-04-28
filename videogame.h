
#ifndef GAMESTOP_VIDEOGAME_H
#define GAMESTOP_VIDEOGAME_H
#include "product.h"
#include <string>
#include <vector>
class Videogame : public virtual Product {
protected:
    std::string name;
    std::string genre;
    std::vector<std::string> compatible_consoles;
public:
    Videogame();
    Videogame(std::string name,std::string genre,std::vector<std::string >& compatible_consoles,int stock_price, int stock_quantity);
    virtual ~Videogame();
    Videogame &operator=(const Videogame &);
    Videogame(const Videogame& obj);
    std::string get_genre() const;
    void display(std::ostream& cout) override;
    void read(std::istream& is,bool file_read) override;
    friend std::istream& operator>>(std::istream& is,Videogame& obj);
    friend std::ostream& operator<<(std::ostream& cout,Videogame& obj);
};
#endif //GAMESTOP_VIDEOGAME_H