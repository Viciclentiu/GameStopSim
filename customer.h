#ifndef GAMESTOP_CUSTOMER_H
#define GAMESTOP_CUSTOMER_H
#include <string>
#include <vector>
#include "product.h"
#include "console.h"
class Customer {
private:
    std::string name;
    float wallet;
    std::vector<std::string> preferences;
    std::vector<Console*> owned_consoles;
    public:
    Customer();
    Customer(std::string name, float wallet, std::vector<std::string> preferences,std::vector<Console*> &owned_consoles);
    Customer(const Customer &customer);
    ~Customer();
    Customer& operator=(const Customer &customer);
    bool decide_purchase(Product* p);
    float calculate_satisfaction(std::vector<Product*>& cart);
    float trade_in(Product* p);
};
#endif //GAMESTOP_CUSTOMER_H