#include "customer.h"
#include "merch.h"

#include <vector>
#include <string>
#include <iostream>

#include "videogame.h"

Customer::Customer() {
    this->name="None";
    this->wallet=0.0;
    this->preferences.push_back("None");
    this->owned_consoles.push_back("None");
}

Customer::Customer(std::string name, float wallet, std::vector<std::string> preferences, std::vector<std::string> owned_consoles) {
    this->name = name;
    this->wallet=wallet;
    for(int i=0;i<preferences.size();i++) {
        this->preferences.push_back(preferences[i]);
    }
    for(int i=0;i<owned_consoles.size();i++) {
        this->owned_consoles.push_back(owned_consoles[i]);
    }
}

Customer::Customer(const Customer &customer) {
    this->name=customer.name;
    this->wallet=customer.wallet;
    for(int i=0;i<customer.preferences.size();i++) {
        this->preferences.push_back(customer.preferences[i]);
    }
    for(int i=0;i<customer.owned_consoles.size();i++) {
        this->owned_consoles.push_back(customer.owned_consoles[i]);
    }

}

Customer::~Customer() {}
Customer& Customer::operator=(const Customer &obj) {
    if (this == &obj) {
        return *this;
    }
    this->name=obj.name;
    this->wallet=obj.wallet;
    this->preferences.clear();
    for (int i=0;i<obj.preferences.size();i++) {
        this->preferences.push_back(obj.preferences[i]);
    }
    this->owned_consoles.clear();
    for (int i=0;i<obj.owned_consoles.size();i++) {
        this->owned_consoles.push_back(obj.owned_consoles[i]);
    }
    return *this;
}
bool Customer::decide_purchase(Product* p) {
    float market_cap = p->get_price_per_product();
    // VAT is 20% in Romania for some reason
    if (this->wallet <= market_cap * 1.2) {
        return false;
    }
    if (Videogame* v = dynamic_cast<Videogame*>(p)) {
        for (std::string& pref : this->preferences) {
            if (v->get_genre() == pref) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return true;
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
    float base_value = p->get_price_per_product();
    float offer = base_value * 0.7;
    if (this->wallet < 20.0f) {
        offer *= 0.85;
    }
    if (dynamic_cast<Merchandise*>(p)) {
        offer *= 0.5;
    }

    return offer;
}
std::string Customer::get_name() {
    return this->name;
}
float Customer::get_wallet() {
    return this->wallet;
}