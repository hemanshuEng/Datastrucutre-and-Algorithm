#include <iostream>

/**
 * Number Swapper : write a function to swap two numbers in place (That is , without temporary variable)
 */
void swapUsingXor (int &a, int &b) {
     a = a^b;
     b = a^b;
     a = a^b;
}
void swapUsingdiff (int &a, int &b) {
    a = a-b;
    b = a+b;
    a = b-a;
}
int main() {
    int a = 10;
    int b = 15;
    std::cout << "a:" <<a <<std::endl;
    std::cout << "b:" <<b<<std::endl;
    swapUsingXor(a,b);
    std::cout << "a:" <<a <<std::endl;
    std::cout << "b:" <<b<<std::endl;
    swapUsingdiff(a,b);
    std::cout << "a:" <<a <<std::endl;
    std::cout << "b:" <<b<<std::endl;
    return 0;
}
