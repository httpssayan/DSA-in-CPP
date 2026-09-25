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

void removeNode(Node* &head, Node* temp){
    if(temp==NULL) return;

    if(temp->prev) temp->prev->next=temp->next;
    else head=temp->next;

    if(temp->next) temp->next->prev=temp->prev;

    delete temp;
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
    Node* third = new Node(30);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    removeNode(head, second);

    printList(head);

    return 0;
}