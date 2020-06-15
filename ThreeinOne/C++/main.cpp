#include <iostream>
#include "FixedMultiStack.h"
int main() {
    FixedMultiStack *a = new FixedMultiStack(12);
    a->push(1,12);
    std::cout<< a->top(1)<<std::endl;
    a->push(1,13);
    std::cout<< a->top(1)<<std::endl;
    a->pop(1);
    std::cout<< a->top(1)<<std::endl;
    a->pop(1);
    std::cout<< a->top(1)<<std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
