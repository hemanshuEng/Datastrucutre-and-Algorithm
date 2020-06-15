#include <iostream>
/**
 * Stack Using linked list
 *
 */
 struct Node {
     int data;
     struct Node* next;
 };
 struct Node* top = nullptr;
 bool isEmpty(Node* head) {
     return head == nullptr;
 }
 void push(int val) {
     auto *newNode = (struct Node*)malloc(sizeof(struct Node));
     newNode->data = val;
     newNode->next = top;
     top = newNode;
 }
 void pop() {
     if(isEmpty(top)) {
         std::cout <<"stack underflow" <<std::endl;
     } else {
         std::cout <<"The popped element is " << top->data <<std::endl;
         top = top->next;
     }
 }
 void display(Node* head) {
     struct Node* ptr = head;
     while(!isEmpty(ptr)) {
         std::cout<<ptr->data<<std::endl;
         ptr = ptr->next;
     }
 }
int main() {
    int ch, val;
    std::cout<<"1) Push in stack"<<std::endl;
    std::cout<<"2) Pop from stack"<<std::endl;
    std::cout<<"3) Display stack"<<std::endl;
    std::cout<<"4) Exit"<<std::endl;
    do {
        std::cout<<"Enter choice: "<<std::endl;
        std::cin>>ch;
        switch(ch) {
            case 1: {
                std::cout<<"Enter value to be pushed:"<<std::endl;
                std::cin>>val;
                push(val);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display(top);
                break;
            }
            case 4: {
                std::cout<<"Exit"<<std::endl;
                break;
            }
            default: {
                std::cout<<"Invalid Choice"<<std::endl;
            }
        }
    }while(ch!=4);
    return 0;
}
