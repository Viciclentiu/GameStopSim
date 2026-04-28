#include "customer.h"
#include "merch.h"

#include <vector>
#include <string>
#include <iostream>

#include "bundle.h"
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
        }
    }
    else if (Bundle* b = dynamic_cast<Bundle*>(p)) {
        market_cap = b->price_discount()*1.2;
        if (this->wallet <= market_cap * 1.2 ) {
            return false;
        }
    }
    else {
        return true;
    }
    return false;
}
float Customer::calculate_satisfaction(std::vector<Product*>& cart) {
    int purchased_products=0;
    if (cart.empty())
        throw std::runtime_error("Cart is empty!");
    for(int i=0;i<cart.size();i++) {
        if (this->decide_purchase(cart[i])) {
            purchased_products++;
        }
    }
    return (float) purchased_products/cart.size() * 100.0f;
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
std::string Customer::get_name() const {
    return this->name;
}
float Customer::get_wallet() const {
    return this->wallet;
}
void Customer::set_wallet(float new_ammount) {
    this->wallet = new_ammount;
}
std::istream& operator>>(std::istream& is,Customer& customer) {
    std::cout<<"Enter customer name:\n";
    std::string name;
    getline(is,name);
    customer.name = name;
    std::cout<<"Enter wallet:\n";
    float wallet;
    std::vector<std::string> preferences;
    std::vector<std::string> owned_consoles;
    is>>wallet;
    is.get();
    std::cout<<"Enter the number of preferences:\n";
    int prefs;
    is>>prefs;
    is.get();
    std::cout<<"Enter preferences:\n";
    for(int i=0;i<prefs;i++) {
        std::string preference;
        getline(is,preference);
        customer.preferences.push_back(preference);
    }
    int no_consoles;
    std::cout<<"Enter the number of consoles owned:\n";
    is>>no_consoles;
    std::cout<<"Enter consoles\n";
    for(int i=0;i<no_consoles;i++) {
        std::string console;
        getline(is,console);
        customer.owned_consoles.push_back(console);
    }
    return is;
}
std::ostream& operator<<(std::ostream& cout,Customer& customer) {
    cout<<"Name"<< customer.name<<"\n";
    cout<<"Wallet"<< customer.wallet<<"\n";
    cout<<"Preferences:\n";
    for (int i=0;i<customer.preferences.size();i++) {
        cout<<customer.preferences[i]<<"\n";
    }
    cout<<"Owned_consoles\n";
    for (int i=0;i<customer.owned_consoles.size();i++) {
        cout<<customer.owned_consoles[i]<<"\n";
    }
    return cout;
}