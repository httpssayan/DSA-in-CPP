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

void insertAtK(Node* &head, int k, int x) {
    Node* newNode = new Node(x);

    if(k == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    newNode->next = temp->next;
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
    head->next->next->next = new Node(40);

    insertAtK(head, 3, 25);

    printList(head);

    return 0;
}