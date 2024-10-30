#include <iostream>
#include <fstream>
#include "bankaccount.h"
using namespace std;
int main() {
    SavingsAccount<int> savings1 = SavingsAccount<int>(1, 20, 2.0);
    SavingsAccount<double> savings2 = SavingsAccount<double>(2, 40.0, 2.0);
    CheckingAccount<int> checking1 = CheckingAccount<int>(3,30, 1000);
    CheckingAccount<double> checking2 = CheckingAccount<double>(4,50.0, 1000);
    BankAccount<int> bankAccount = BankAccount<int>(1,30);
    try {

    checking2.withdraw(20.0);
    } catch (InsufficientFundsException e) {
        cout<<"Low balance"<<endl;
    } catch (InvalidAmountException e) {
        cout<<"Invalid amount"<<endl;
    }
    ofstream of("account.txt");
    savings1.saveToFile(of);
    savings2.saveToFile(of);
    ifstream ifstream1("account2.txt");
    //BankAccount account = loadFromFile<int>(ifstream1);
    return 0;
}
