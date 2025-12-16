#include<iostream>
#include "bank_accout.h"


BankAccout::BankAccount(int accountNumber, int accountBalance) : accountNumber(accounNumber), accountBalance(accountBalance) {}


int BankAccount::getBalance(){
    return accountBalance;
}


void BankAccout::withdraw(int money){
    accountBalance -= money;
}

void BankAccout::deposit(int money){
    accountBalance += money;
}
