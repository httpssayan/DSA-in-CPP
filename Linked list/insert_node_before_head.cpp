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

void insertBeforeHead(Node*& head, int x) {

    Node* newNode = new Node(x);

    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
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

    insertBeforeHead(head, 5);

    printList(head);

    return 0;
}