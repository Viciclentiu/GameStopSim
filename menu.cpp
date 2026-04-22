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
    std::cout << "0. Exit\n";
    std::cout << "Select your choice: ";
}