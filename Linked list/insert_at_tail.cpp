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

void insertAtTail(Node* &head, int x) {
    Node* newNode = new Node(x);

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
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

    insertAtTail(head, 40);

    printList(head);

    return 0;
}