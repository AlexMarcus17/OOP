//#include <iostream>
//#include <utility>
//using namespace std;
//template<typename T>
//void swapvalue(T& a, T& b) {
//    std::swap(a, b);
//}
//
//// Example usage
//int main() {
//    int int1 = 5, int2 = 10;
//    double double1 = 3.4, double2 = 6.8;
//    string str1 = "Hello", str2 = "World";
//
//    swapvalue(int1, int2);
//    swapvalue(double1, double2);
//    swapvalue(str1, str2);
//
//    cout << "int1 = " << int1 << ", int2 = " << int2 << endl;
//    cout << "double1 = " << double1 << ", double2 = " << double2 << endl;
//    cout << "str1 = " << str1 << ", str2 = " << str2 << endl;
//
//    return 0;
//}

#include <iostream>
#include <string>

template<typename T>
T findmax(const T& a, const T& b) {
    return (a < b) ? b : a;
}

int main() {
    int int1 = 5, int2 = 10;
    double double1 = 3.4, double2 = 6.2;
    std::string str1 = "apple", str2 = "banana";

    std::cout << "Max of " << int1 << " and  " << int2 << " is: " << findmax(int1, int2) << std::endl;

    std::cout << "Max of " << double1 << " and " << double2 << " is: " << findmax(double1, double2) << std::endl;

    std::cout << "Max of " << str1 << " and " << str2 << " is: " << findmax(str1, str2) << std::endl;



    return 0;
}

