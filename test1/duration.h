//
// Created by User on 27.03.2024.
//
#pragma once
#include <ostream>
class Duration {
private:
    int amount;
    char unit;
public:
    Duration();
    Duration(int amount, char unit);
    int getSeconds();
    int get(char unit);
    int compare(Duration other);
    void plus(Duration other);
    void print();
};
