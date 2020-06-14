#include <iostream>
class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
    void appendToTail(int d) {
        Node *end = new Node(d);
        Node *n = this;
        while(n->next != nullptr) {
            n = n->next;
        }
        n->next = end;
    }
    void appendToFront(int d) {
        Node *Front = new Node(d);
        Front->next = this;
    }
};

int main() {
    Node *n = new Node(10);
    n->appendToTail(12);
    n->appendToTail(14);
    n->appendToTail(16);
    n->appendToFront(17);
    while(n != nullptr) {
        std::cout << n->data <<std::endl;
        n = n->next;
    }
    return 0;
}