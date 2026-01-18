#ifndef ORDER_H
#define ORDER_H

class Order{

private:
    
    int id;
    double price;
    int qty;
    bool isBuy;

public:
    Order(int id, double price, int qty, bool isBuy);
    
    int getId();
    double getPrice();
    int getQty();
    bool getIsBuy();
    void printOrder();
    void setQty(int change);

    bool operator<(const Order& other) const{
        return price < other.price;
    }

};

#endif
