#include<iostream>
#include<iomanip>
#include "Trade.h"

Trade::Trade(long id, double price_btc, double qty, double quote_qty, long long time, bool is_buyer_maker) : id(id), price_btc(price_btc), qty(qty), quote_qty(quote_qty), time(time), is_buyer_maker(is_buyer_maker) {}


long Trade::getId(){
    return id;
};

long long Trade::getTime(){
    return time;
};

double Trade::getQuoteQty(){
  return quote_qty;  
};

double Trade::getPriceBtc(){
    return price_btc;  
};

double Trade::getQty(){
    return qty;  
};

bool Trade::getIsBuyerMaker(){
    return is_buyer_maker;
}

void Trade::printTrade(){
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "id: " << id << " BTC price: " << price_btc << " Quantity bought: " << qty << " Price: " << quote_qty << " Time: " << time << " Is buyer a maker?: " << is_buyer_maker << '\n';
}

