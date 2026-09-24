#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void insertBeforeX(Node* &head, int x, int value) {
    Node* newNode = new Node(value);

    // If X is at the head
    if(head != NULL && head->data == x) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp != NULL && temp->next != NULL) {

        if(temp->next->data == x) {
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }

        temp = temp->next;
    }
}

void printList(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    insertBeforeX(head, 20, 15);

    printList(head);

    return 0;
}