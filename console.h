
#ifndef GAMESTOP_CONSOLE_H
#define GAMESTOP_CONSOLE_H
#include <string>
#include <vector>
#include "product.h"
#include "videogame.h"

class Console : public virtual Product {
protected:
    std::string name;
    std::string description;
    std::vector<std::string> specs;
public:
    Console();
    Console(std::string name,std::string description, std::vector<std::string> specs,int stock_price, int stock_quantity);
    virtual ~Console();
    Console(const Console &);
    Console &operator=(const Console &);
    void display(std::ostream& cout) override;
    void read(std::istream& is) override;
    friend std::istream& operator>>(std::istream& is,Console& obj);
    friend std::ostream& operator<<(std::ostream& cout,const Console& obj);
};
#endif //GAMESTOP_CONSOLE_H