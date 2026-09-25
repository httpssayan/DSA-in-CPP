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

void insertBeforeTail(Node* head, int x) {

    if(head == NULL)
        return;

    Node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    Node* newNode = new Node(x);

    newNode->prev = temp->prev;
    newNode->next = temp;

    temp->prev->next = newNode;
    temp->prev = newNode;
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

    insertBeforeTail(head, 25);

    printList(head);

    return 0;
}