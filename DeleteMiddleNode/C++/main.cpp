/**
 *Delete Middle Node : Implement an algorithm to delete a node in the middle(i.e any node but the
 * first and last node , not necessarily the exact middle)of linked list, given only access to that
 * node
 */

#include <iostream>

struct Node {
    char data;
    Node *next;
    explicit Node(char d) : data{ d }, next{ nullptr } { };
};

/**
 * Insert to the head of the list
 * @param head - Current head of list
 * @param data - new node's data
 */
void insert( Node * & head, int data ) {
    Node * newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}
/**
 * printList - Helper routine to print the list
 * @param head - Current head of the list.
 */
void printList( Node * head ) {
    while(head) {
        std::cout << head->data << "-->";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

bool deleteNode(Node *n) {
    if(n == nullptr || n->next == nullptr) {
        return false;
    }
    Node *next = n->next;
    n->data = next->data;
    n->next = next->next;
    return true;
}

int main() {
    Node * head = nullptr;
    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'e');
    insert(head, 'f');
    std::cout << "List: ";
    printList(head);
    deleteNode(head->next->next->next);
    std::cout << "List: ";
    printList(head);
    return 0;
}
