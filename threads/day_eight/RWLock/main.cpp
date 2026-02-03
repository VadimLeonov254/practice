#include<iostream>
#include "RWLock.h"

int main(){
    
    RWLock lock;

    std::thread reader1();
    std::thread reader2();

    std::thread writer1();
    std::thread writer2();


}
