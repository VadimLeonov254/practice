#include<iostream>
#include "order.h"

Order::Order(int id, double price, int qty, bool isBuy) : id(id), price(price), qty(qty), isBuy(isBuy){}


int Order::getId(){
    return id;
}

double Order::getPrice(){
    return price;
}


int Order::getQty(){
    return qty;
}

bool Order::getIsBuy(){
    return isBuy;
}

void Order::printOrder(){
    if(isBuy == true){
        std::cout << "id:" << id << "| buying " << qty << " stocks at the price $" << price; 
    }else{
        std::cout << "id:" << id << "| selling " << qty << " stocks at the price $" << price; 
    }
    std::cout << '\n';
}

void Order::setQty(int change){
    qty = change;
}

