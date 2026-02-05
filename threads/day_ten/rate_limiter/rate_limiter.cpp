#include<iostream>
#include "rate_limiter.h"

RateLimiter::RateLimiter(int maxOpsPerSecond) : maxOpsPerSecond(maxOpsPerSecond) {}

void RateLimiter::tryAcquire(){
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this]{
        return currOps < maxOpsPerSecond;
    });
    currOps++;
    if(currOps == 5){
        currOps = 0;
    }
    cv.notify_all();
}
