#include<iostream>
#include<string>
#include<thread>
#include<fstream>
#include<vector>
#include<chrono>
#include<sstream>
#include "Trade.h"


int main(){
    
    long id;
    long long time;
    double price, qty, quote_qty;
    bool is_buyer;
    int speed;
    std::vector<Trade> queue;
    std::string filename, line;
    std::vector<std::string> converter;
    std::vector<int> latency;
    std::cout << "Enter the filename: ";
    std::cin >> filename;
    std::cout << "Enter the speed you want to replay the market at (ex. 1, 2, 10, etc.): ";
    std::cin >> speed;
    std::ifstream file(filename);
    
    if(!file){
        std::cout << "File does not exist" << '\n';
    }
    
    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string field;

        while(std::getline(ss, field, ',')){
            converter.push_back(field);
        }
    }

    for(int i = 0; i < converter.size()-6; i+=6){
        id = std::stol(converter[i]);
        price = std::stod(converter[i+1]);
        qty = std::stod(converter[i+2]);
        quote_qty = std::stod(converter[i+3]);
        time = std::stoll(converter[i+4]);
        if(converter[i+5] == "True"){
            is_buyer = true;
        }else if (converter[i+5] == "False"){
            is_buyer = false;
        }
        Trade trade = Trade(id, price, qty, quote_qty, time, is_buyer);
        queue.push_back(trade);
    } 
    
    file.close();
    
    
    for(int i = 0; i < queue.size()-1; i++){
        latency.push_back(queue[i+1].getTime() - queue[i].getTime());
    }

    std::cout << "Replaying the market at " << speed << "X speed: " << '\n';
    for(int i = 0; i < queue.size(); i++){
        if(i == 0){
            queue[i].printTrade();
        }else{
            std::this_thread::sleep_for(std::chrono::milliseconds(latency[i]/speed));
            queue[i].printTrade();
        }
    }

}
