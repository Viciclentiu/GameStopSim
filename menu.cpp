#include "menu.h"
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
            ///TODO operator >> for all product derived classes
            //std::cin>>merch;
            this->inventory.push_back(merch);
            break;
        }

        case 2: {
            Product * videogame = new Videogame();
            //std::cin>>videogame;
            this->inventory.push_back(videogame);
            break;
        }
        case 3: {
            Product * console = new Console();
            //std::cin>> console;
            this->inventory.push_back(console);
            break;
        }
        default:
            std::cout<<"Invalid choice\n";
            break;
    }
}
Product* Menu::make_bundle(Videogame*v,Console* p) {
    Product* bundle = new Bundle();
    ///cin>>bundle
    return bundle;
}