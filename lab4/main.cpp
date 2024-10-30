#include <ostream>
#include <iostream>
#include "array.cpp"
using namespace std;


int main() {
    Array a1{10};
    a1.append(1);
    a1.append(2);
    a1.append(3);
    a1.append(4);
    a1.append(5);
    cout<<"Array 1: "<<a1;
    Array a2{a1};
    cout<<"Array 2: "<<a2;
    Array a3{};
    a3 = a1;
    cout<<"Array 3: "<<a3;
    a2.at(0) = 10;
    cout<<"a2[0] = 10\nNow the arrays are:"<<endl;
    cout<<"Array 1: "<<a1;
    cout<<"Array 2: "<<a2;
    cout<<"Array 3: "<<a3;
    return 0;
}
