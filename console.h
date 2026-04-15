
#ifndef GAMESTOP_CONSOLE_H
#define GAMESTOP_CONSOLE_H
#include <string>

#include "product.h"

class Console : public virtual Product {
protected:
    std::string name;
    std::string description;
    std::string specs;
public:
    Console();
    Console(std::string name,std::string description, std::string specs,int stock_price, int stock_quantity);
    virtual ~Console();
    Console(const Console &);
    Console &operator=(const Console &);
    void display() override;
};
#endif //GAMESTOP_CONSOLE_H