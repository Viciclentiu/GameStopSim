
#ifndef GAMESTOP_BUNDLE_H
#define GAMESTOP_BUNDLE_H
#include <vector>
#include "videogame.h"
#include "console.h"
class Bundle : public Videogame, public Console {
private:
    float discount;
    std::vector<int> days_available;
public:
    Bundle();
    Bundle(float discount,std::vector<int> &days_available,Videogame &game, Console &console);
    Bundle(const Bundle &);
    ~Bundle();
    Bundle& operator=(const Bundle &);
    void display(std::ostream& cout) override;
    void read(std::istream& is,bool file_read) override;
    float price_discount();
    int get_last_day_available();
    friend std::istream& operator>>(std::istream& is,Bundle& obj);
    friend std::ostream& operator<<(std::ostream& cout,const Bundle& obj);
};
#endif //GAMESTOP_BUNDLE_H