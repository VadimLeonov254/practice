#include<iostream>
#include<vector>
#include<algorithm>
#include "order.h"

int main(){
    
    bool buysell;
    double pr;
    int qt, pos, retain;
    std::string ans;
    std::string answ = "yes";
    std::vector<Order> buy;
    std::vector<Order> sell;
    

    while(answ == "yes"){
        std::cout << "Do you want to add an order? : ";
        std::cin >> answ;
        if(answ != "yes" && answ != "no"){
            std::cout << "Enter yes or no: ";
            std::cin >> answ;
        }
        if(answ == "no"){
            break;
            std::cout << '\n';
        }
    
        std::cout << "Do you want to buy or sell?" << '\n';
        std::cin >> ans;
        if(ans == "buy"){
            buysell = true;
        }else{
            buysell = false;
        }
        std::cout << "Enter the price: ";
        std::cin >> pr;
    
        std::cout << "Enter the quantity: ";
        std::cin >> qt;

        Order order = Order(1, pr, qt, buysell);
        
        if(buysell == true && sell.size() == 0){
            buy.push_back(order);
            if(buy.size() > 1){
                std::sort(buy.begin(), buy.end());
            }
        }else if (buysell == false && buy.size() == 0){
            sell.push_back(order);
            if(sell.size() > 1){
                std::sort(sell.begin(), sell.end());
            }
        }else if(buysell == true && sell.size() != 0){
                for(int i = 0; i < sell.size(); i++){
                    if(sell[i].getPrice() <= pr){
                        if(sell[i].getQty() >= order.getQty()){
                            sell[i].setQty(sell[i].getQty()-order.getQty());
                            order.setQty(0);
                        }else{
                            order.setQty(order.getQty()-sell[i].getQty());
                            sell[i].setQty(0);
                        }
                    }
                    if(sell[i].getQty() == 0){
                        sell.erase(sell.begin()+i);
                        i--;
                    }
                }
                if(order.getQty() > 0){
                    buy.push_back(order);
                    if(buy.size() > 1){
                        std::sort(buy.begin(), buy.end());
                    }
                }
        }else if(buysell == false && buy.size() != 0){
                for(int i = buy.size()-1; i >= 0; i--){
                    if(buy[i].getPrice() >= pr){
                        if(buy[i].getQty() >= order.getQty()){
                            buy[i].setQty(buy[i].getQty() - order.getQty());
                            order.setQty(0);
                        }else{
                            order.setQty(order.getQty() - buy[i].getQty());
                            buy[i].setQty(0);
                        }
                    }
                    if(buy[i].getQty() == 0){
                        buy.erase(buy.begin()+i);
                    }
                }
                if(order.getQty() > 0){
                    sell.push_back(order);
                    if(sell.size() > 1){
                        std::sort(sell.begin(), sell.end());
                    }
                }
            }   
        std::cout << '\n';
    }

   std::cout << buy.size() << '\n';

    for(int i = 0; i < buy.size(); i++){
        buy[i].printOrder();
        std::cout << '\n';
    }

    for(int i = 0; i < sell.size(); i++){
        sell[i].printOrder();
        std::cout << '\n';
    }


}


