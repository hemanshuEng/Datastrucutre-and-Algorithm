#include <iostream>
#include <limits>
#include <stack>

template<typename T>
class StackMin {
private:
    std::stack<T> stack;
    std::stack<T> minStack;
public:
    T min() {
        if(minStack.empty()) {
            std::cout<<"stack is empty" <<std::endl;
            return std::numeric_limits<T>::max();
        } else {
            return minStack.top();
        }
    }

    template<typename U>
    void push(U &&value) {
        if(minStack.empty() || value <= minStack.top()) {
            minStack.push(value);
            stack.push(value);
        } else {
            stack.push(value);
            minStack.push(minStack.top());
        }
    }
    T pop() {
        auto value = stack.top();
        stack.pop();
        minStack.pop();
        return value;
    }
    T top() {
        return stack.pop();
    }
    bool isEmpty() {
        return stack.empty();
    }
};
int main() {
    StackMin<int> stack;
    for (auto v : {5, 10, 4, 9, 3, 3, 8, 2, 2, 7, 6})
    {
        stack.push(v);
        std::cout << "Pushed value: " << v << ", min value: " << stack.min() << std::endl;
    }
    while (!stack.isEmpty())
    {
        auto v = stack.pop();
        std::cout << "Popped value: " << v;
        if (stack.isEmpty())
            std::cout << ", stack is empty" << std::endl;
        else
            std::cout << ", min value: " << stack.min() << std::endl;
    }
    return 0;
}
