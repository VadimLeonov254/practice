#ifndef TRADE_H
#define TRADE_H

class Trade{
private:

    long id;
    double price_btc;
    double qty;
    double quote_qty;
    long long time;
    bool is_buyer_maker;

public:
    Trade(long id, double price_btc, double qty, double quote_qty, long long time, bool is_buyer_maker);
    long getId();
    double getPriceBtc();
    double getQty();
    double getQuoteQty();
    long long getTime();
    bool getIsBuyerMaker();
    void printTrade();
};

#endif
