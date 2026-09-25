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

Node* reverseDLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        swap(temp->prev, temp->next);
        temp=temp->prev;
    }

    if(head != NULL)
        head = head->prev;

    return head;
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
    Node* fourth = new Node(40);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    head = reverseDLL(head);

    printList(head);

    return 0;
}