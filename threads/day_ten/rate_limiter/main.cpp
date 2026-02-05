#include<iostream>
#include<thread>
#include "rate_limiter.h"
#include<atomic>

std::atomic<int> i{0};

int main(){
    
    int n;
    std::cout << "How many operations per second?" << '\n';
    std::cin >> n;

    RateLimiter limiter = RateLimiter(n);

    std::thread t1([&](){
        while(i < 101){
            limiter.tryAcquire();
            i++;
            std::cout << i << '\n';
        }
    });
 
    std::thread t2([&](){
        while(i < 101){
            limiter.tryAcquire();
            i++;
            std::cout << i << '\n';
        }
    });
 
    t1.join();
    t2.join();
}
