//
#ifndef GAMESTOP_PRODUCT_H
#define GAMESTOP_PRODUCT_H
class Product {
protected:
    const int product_id;
    static int product_no;
    float stock_price;
    int stock_quantity;
    public:
    Product();
    Product(int stock_price, int stock_quantity);
    Product(const Product&);
    virtual ~Product();
    virtual void display() =0;
    Product &operator=(const Product &);
    float get_price_per_product();
    int get_stock_quantity();
    void set_stock_quantity(int stock_quantity);
    void reduce_stock(int amount);
};
#endif //GAMESTOP_PRODUCT_H