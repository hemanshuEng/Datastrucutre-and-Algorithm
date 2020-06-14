#include <iostream>
#include<bits/stdc++.h>
#include<unordered_set>
/**
 * Remove Duplicates: Write code to remove duplicates from un unsorted linked list.
 * Follow up :
 * How would you solve this problem if a temporary buffer is not allowed
 */
struct Node {
    int data;
    struct Node *next;
};

struct Node *newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void RemoveDuplicates(struct Node *start) {
    std::unordered_set<int> seen;
    struct Node *current = start;
    struct Node *prev = nullptr;
    while(current != nullptr) {
        if(seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete(current);
        } else {
            seen.insert(current->data);
            prev= current;
        }
        current = prev->next;
    }
}
void printList(struct Node *node)
{
    while (node != nullptr)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
int main() {
    struct Node *start = newNode(10);
    start->next = newNode(12);
    start->next->next = newNode(11);
    start->next->next->next = newNode(11);
    start->next->next->next->next = newNode(12);
    start->next->next->next->next->next =
            newNode(11);
    start->next->next->next->next->next->next =
            newNode(10);

    printf("Linked list before removing duplicates : \n");
    printList(start);

    RemoveDuplicates(start);

    printf("\nLinked list after removing duplicates : \n");
    printList(start);

    return 0;
    return 0;
}
