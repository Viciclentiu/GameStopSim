#include "customer.h"
#include <vector>
#include <string>
#include <iostream>
Customer::Customer() {
    this->name="None";
    this->wallet=0.0;
    this->preferences.push_back("None");
    Console* console = new Console();
    this->owned_consoles.push_back(console);
    delete console;
}

Customer::Customer(std::string name, float wallet, std::vector<std::string> preferences, std::vector<Console *> &owned_consoles) {
    this->name = name;
    this->wallet=wallet;
    for(int i=0;i<preferences.size();i++) {
        this->preferences.push_back(preferences[i]);
    }
    for(int i=0;i<owned_consoles.size();i++) {
        this->owned_consoles.push_back(new Console(*owned_consoles[i]));
    }
}

Customer::Customer(const Customer &customer) {
    this->name=customer.name;
    this->wallet=customer.wallet;
    for(int i=0;i<customer.preferences.size();i++) {
        this->preferences.push_back(customer.preferences[i]);
    }
    for(int i=0;i<customer.owned_consoles.size();i++) {
        this->owned_consoles.push_back(new Console(*customer.owned_consoles[i]));
    }

}

Customer::~Customer() {
    for (int i=0;i<this->owned_consoles.size();i++) {
        delete this->owned_consoles[i];
    }
}
Customer& Customer::operator=(const Customer &obj) {
    if (this == &obj) {
        return *this;
    }
    this->name=obj.name;
    this->wallet=obj.wallet;

    for (int i=0;i<obj.preferences.size();i++) {
        this->preferences.push_back(obj.preferences[i]);
    }
    for (int i=0;i<this->owned_consoles.size();i++) {
        delete this->owned_consoles[i];
    }
    for (int i=0;i<obj.owned_consoles.size();i++) {
        this->owned_consoles.push_back(new Console(*obj.owned_consoles[i]));
    }
    return *this;
}
bool Customer::decide_purchase(Product* p) {
    float market_cap = p->get_price_per_product();
    // VAT is 20% in Romania for some reason
    if (this->wallet >= market_cap * 1.2)
        return true;
    return false;
}
float Customer::calculate_satisfaction(std::vector<Product*>& cart) {
    int purchased_products=0;
    for(int i=0;i<cart.size();i++) {
        if (this->decide_purchase(cart[i])) {
            purchased_products++;
        }
    }
    return (float)(purchased_products/cart.size()) * 100.0;
}

float Customer::trade_in(Product *p) {
    float market_value = p->get_price_per_product();
    if (this->wallet <50.0) {
        return (float) market_value * 0.6;
    }
    return market_value * 0.8;
}