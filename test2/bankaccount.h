//
// Created by User on 24.04.2024.
//

#ifndef TEST2_BANKACCOUNT_H
#define TEST2_BANKACCOUNT_H

#endif //TEST2_BANKACCOUNT_H

#include <iostream>
#include <fstream>
using namespace std;


class InvalidAmountException : std::exception {

};

class InsufficientFundsException : std::exception {

};

template <typename T>

class BankAccount {
protected:
    long accountNumber;
    T balance;
public:
    BankAccount(long aNumber, T bal) : accountNumber(aNumber), balance(bal){}
    void deposit(T amount)
    {
        if(amount > 0) {
            balance += amount;
        } else {
            throw InvalidAmountException();
        }
    }

    virtual void withdraw(T amount)
    {
        if(amount < 0) {
            throw InvalidAmountException();
        } else if(amount > balance) {
            throw InsufficientFundsException();
        } else {
            balance-=amount;
        }
    }

    virtual void saveToFile(std::ofstream &file) {
        file<<"Account Number: "<<accountNumber<<endl;
        file<<"Balance: "<<balance<<endl;
    }
};

template <typename T>
class SavingsAccount : public BankAccount<T> {
private:
    double interestRate;
public:
    SavingsAccount(long aNumber, T bal, double rate) : BankAccount<T>(aNumber, bal) , interestRate(rate) {}
    void saveToFile(std::ofstream &file) override {
        file<<"Savings Account"<<endl;
        file<<"Account Number: "<<BankAccount<T>::accountNumber<<endl;
        file<<"Balance: "<<BankAccount<T>::balance<<endl;
        file<<"Interest Rate: "<<interestRate<<endl;
    };

};
template <typename T>
class CheckingAccount : BankAccount<T> {
private:
    T overdraftLimit;
public:
    CheckingAccount(long aNumber, T bal, T limit) : BankAccount<T>(aNumber, bal) , overdraftLimit(limit) {}
    void saveToFile(std::ofstream &file) override {
        file<<"Checking Account"<<endl;
        file<<"Account Number: "<<BankAccount<T>::accountNumber<<endl;
        file<<"Balance: "<<BankAccount<T>::balance<<endl;
        file<<"Overdraft Limit: "<<overdraftLimit<<endl;
    };
    void withdraw (T amount) override {
        if(amount < 0) {
            throw InvalidAmountException();
        } else if(amount > BankAccount<T>::balance + overdraftLimit) {
            throw InsufficientFundsException();
        } else {
            BankAccount<T>::balance-=amount;
        }
    }
};

template <typename T>
BankAccount<T> loadFromFile(std::ifstream &file) {
    string type;
    file>>type;
    if(type=="savings") {
        long num; file>>num;
        T balance; file>>balance;
        double interest; file>>interest;
        return SavingsAccount<T>(num,balance,interest);
    } else if(type=="checking") {
        long num; file>>num;
        T balance; file>>balance;
        T limit; file>>limit;
        return CheckingAccount<T>(num,balance,limit);
    }
}