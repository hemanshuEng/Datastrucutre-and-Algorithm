/**
 *Palindrome: Implement a function to check if linked list is a palindrome
 *
 */

#include <iostream>
#include <random>
struct Node {
    int data;
    Node *next;
    explicit Node(int d) : data{ d }, next{ nullptr } { };
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

Node *reverse(Node* list) {
    if(list == nullptr || (list->next == nullptr)){
        return nullptr;
    }
    Node *head = nullptr;
    while(list != nullptr) {
        Node *n = new Node(list->data);
        n->next = head;
        head = n;
        list = list->next;
    }
    return head;
}
bool isEqual(Node *list1, Node* list2) {
    while(list1 != nullptr && list2 != nullptr) {
        if(list1->data != list2->data) {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return list1== nullptr && list2 == nullptr;
}
bool isPalidrome(Node* list) {
    Node* reversed = reverse(list);
    return isEqual(list, reversed);
}
int main() {
    Node * head = nullptr;
    insert(head,1);
    insert(head,1);
    insert(head,3);
    insert(head,1);
    insert(head,1);
    std::cout << "List: ";
    printList(head);
    std::cout << std::boolalpha<< isPalidrome(head) <<std::endl;
    return 0;
}
