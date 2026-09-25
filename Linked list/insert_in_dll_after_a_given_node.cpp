#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

void insertAfter(Node* temp, int x){
    Node* newNode= new Node(x);

    newNode->prev=temp;
    newNode->next=temp->next;

    if(temp->next) temp->next->prev=newNode;
    temp->next=newNode;
}

void printList(Node* head) {

    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {

    Node* head = new Node(10);
    Node* second = new Node(20);

    head->next = second;
    second->prev = head;

    insertAfter(head, 15);

    printList(head);

    return 0;
}