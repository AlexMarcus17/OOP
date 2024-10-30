#include <iostream>
using namespace std;

class BankAccount {

private:
    int balance;
    int number;
    string name;

public:
    BankAccount(int balance, int number, string name) {
        this->balance = balance;
        this->number = number;
        this->name = name;

    }

    void withdraw(int sum){
        this->balance = this->balance - sum;
    }
    void deposit(int sum){
        this->balance = this->balance + sum;
    }
    friend ostream& operator<<(ostream& os, const BankAccount& account) {
        os << "Name: " << account.name << endl;
        os << "Balance: " << account.balance << endl;
        os << "Number: " << account.number << endl;
        return os;
    }
};
