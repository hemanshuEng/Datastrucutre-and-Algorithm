/**
 *Write code to partition a linkedlist around a value x, such that all nodes less than x
 * come before all nodes greater than or equal to x.(Important: The partition element x can appear
 * anywhere in the "right partition" it doesnot need to appear between the left and right partitions
 * the additional spacing the example below indicates the partition.
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

Node* partition(Node *listhead, int x) {
    Node * head = nullptr;
    Node * headInitial = nullptr;   /*The initial node of list head*/
    Node * tail = nullptr;
    Node * tailInitial = nullptr;   /*The initial node of list tail*/
    Node * curr = listhead;
    while( curr != nullptr ) {
        Node * nextNode = curr->next;
        if ( curr->data < x ) {
            if (head == nullptr) {
                head = curr;
                headInitial = head;
            }
            //insert curr node to head list
            head->next = curr;
            head = curr;
        } else {
            if (tail == nullptr) {
                tail = curr;
                tailInitial = tail;
            }
            // insert curr node to tail list
            tail->next = curr;
            tail = curr;
        }
        curr = nextNode;
    }
    head->next = tailInitial;  /*Now, we connect the head list to tail list.*/
    tail->next = nullptr;
    return headInitial;
}

int main() {
    Node * head = nullptr;
    for (int i = 0; i < 10; i++) {
        insert(head, rand()%9);
    }
    std::cout << "List: ";
    printList(head);
    std::cout << " Partition List: ";
    printList(partition(head,5));
    return 0;
}
