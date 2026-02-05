#ifndef RATE_LIMITER_H
#define RATE_LIMITER_H
#include<iostream>
#include<condition_variable>


class RateLimiter{
private:
    int currOps = 0;
    int maxOpsPerSecond;
    std::mutex mtx;
    std::condition_variable cv;

public:
    RateLimiter(int maxOpsPerSecond);

    void tryAcquire();

};

#endif
