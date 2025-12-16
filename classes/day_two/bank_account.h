#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


class BankAccount{

private: 
    int accountNumber = 123;
    int accountBalance;

public:
    int getBalance();
    void withdraw(int money);
    void deposit(int money);

};



#endif 
