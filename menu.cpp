#include "menu.h"
Menu::~Menu() {
    for (Product * p : inventory) {
        delete p;
    }
}
Menu::Menu() {
    this->inventory.clear();
    this->funds = 0.0;
    this->running = true;
}
void Menu::displayMenu() {
    std::cout<<"WELCOME TO:\n";
    std::cout<<R"(
 ______     ______     __    __     ______     ______     ______   ______     ______
/\  ___\   /\  __ \   /\ "-./  \   /\  ___\   /\  ___\   /\__  _\ /\  __ \   /\  == \
\ \ \__ \  \ \  __ \  \ \ \-./\ \  \ \  __\   \ \___  \  \/_/\ \/ \ \ \/\ \  \ \  _-/
 \ \_____\  \ \_\ \_\  \ \_\ \ \_\  \ \_____\  \/\_____\    \ \_\  \ \_____\  \ \_\
  \/_____/   \/_/\/_/   \/_/  \/_/   \/_____/   \/_____/     \/_/   \/_____/   \/_/

)"<<'\n';
    std::cout << "1. Take care of a customer\n";
    std::cout << "2. Add a new product\n";
    std::cout << "3. See the store's stock\n";
    std::cout << "4. See its funds\n";
    std::cout << "5. Make a bundle\n";
    std::cout << "0. Exit\n";
    std::cout << "Select your choice: ";
}
///TODO add other functions in the header file
void Menu::add_product() {
    std::cout<<"Please input the product you want to add:\n";
    std::cout<<"1. Merchandise\n";
    std::cout<<"2. Videogame\n";
    std::cout<<"3. Console\n";
    int type;
    std::cin>>type;
    switch (type) {
        case 1: {
            Product* merch = new Merchandise();
            std::cin>> *merch;
            this->inventory.push_back(merch);
            break;
        }

        case 2: {
            Product * videogame = new Videogame();
            std::cin >> *videogame;
            this->inventory.push_back(videogame);
            break;
        }
        case 3: {
            Product * console = new Console();
            std::cin >> *console;
            this->inventory.push_back(console);
            break;
        }
        default:
            std::cout<<"Invalid choice\n";
            break;
    }
}
void Menu::make_bundle() {
    Product* bundle = new Bundle();
    std::cin>> *bundle;
    this->inventory.push_back(bundle);
}


void Menu::customer_visit() {
    Customer visitor("Gioni", rand()%100,{"Survival","Horror"},{"PS5"});
    std::cout<<"Customer:" << visitor.get_name()<<"has entered the store with $" <<visitor.get_wallet()<<'\n';
    bool bought= false;
    float profit=0;
    std::vector<Product*> cart;
    for (Product * p : inventory) {
        if (p->get_stock_quantity()<=0)
            continue;
        if (visitor.decide_purchase(p)) {
            p->reduce_stock(1);
            cart.push_back(p);
            visitor.set_wallet(visitor.get_wallet() - p->get_price_per_product()* 1.2);
            profit+= p->get_price_per_product()*1.2;
            bought= true;
            std::cout<<"[Sale]" << visitor.get_name()<<"bought ";
            p->display();
            if (visitor.get_wallet() <= 0) {
                break;
            }
        }
    }

    if (!bought) {
        std::cout<< "The customer didn't buy anything";
    }
    else {
        this->funds += profit;
        float satisfaction = visitor.calculate_satisfaction(cart); // Pasăm coșul de cumpărături
        std::cout << "Customer satisfaction for this visit: " << satisfaction << "%\n";

        if (satisfaction > 80.0) {
            std::cout << "Excellent service! The customer might come back.\n";
        }
        std::cout<<"Day's over. What you earned: "<< profit<<" USD\n";
    }
}

void Menu::run() {
    int choice;

    while (running) {
        this->displayMenu();
        std::cin>>choice;
        ///try catch here
        switch (choice) {
            case 1: {
                this->customer_visit();
                break;
            }
            case 2: {
                add_product();
                break;
            }
            case 3: {
                std::cout<<"\n ----CURRENT STOCK ---- \n";
                for (Product* p : inventory) {
                    p->display();
                    std::cout<<"-----------------------\n";
                }
                break;
            }
            case 4:
                std::cout<<"Store Funds: $"<<this->funds<<"\n";
                break;
            case 5:
                this->make_bundle();
                break;
            case 0:
                std::cout<<"Exiting program... Goodbye!\n";
                this->running = false;
                break;
            default:
                std::cout<<"Invalid choice. Please try again!\n";
                break;
        }
    }
}