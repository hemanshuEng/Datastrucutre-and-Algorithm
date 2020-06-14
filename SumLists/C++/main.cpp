/**
 *Sums Lists: you have numbers represented by a linked list , where each node contains a single
 * digit.the digits are stored in reverse order, such that the 1's digit is at the head of the list.
 * Write a functions that adds the two number and returns the sum as a linked list.
 * Example
 * input L (7->1->6)+ (5->9->2) that is 617 +295
 * Output: 2->1->7 that is 912
 */

#include <iostream>

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

Node *SumLists(Node* list1, Node* list2) {
    Node* list3 = nullptr;
    Node* listTail = nullptr;
    int carry = 0;
    while(list1 != nullptr || list2 != nullptr) {
        int first = list1 ? list1->data: 0;
        int second = list2 ?list2->data: 0;
        int sum = first + second + carry;
        Node *temp = new Node(sum %10);
        if(list3 == nullptr) {
            list3 = temp;
        } else {
            listTail->next = temp;
        }
        listTail = temp;
        carry = sum / 10;
        if(list1)  {
            list1 = list1->next;
        }
        if(list2) {
            list2 = list2->next;
        }
    }
    if ( carry > 0 ) {
        listTail->next = new Node(carry);
    }
    return list3;
}
int main() {
    Node * list1 = nullptr;
    insert(list1, 6);
    insert(list1, 1);
    insert(list1, 7);
    insert(list1, 7);
    std::cout << "List1:  ";
    printList(list1);

    //making list2 for number 295
    Node * list2 = nullptr;
    insert(list2, 2);
    insert(list2, 9);
    insert(list2, 5);
    std::cout << "List2:  ";
    printList(list2);
    Node *list3 = SumLists(list1, list2);
    printList(list3);
    return 0;
}
