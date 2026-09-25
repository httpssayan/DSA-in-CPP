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

void insertBeforeKth(Node*& head, int k, int x) {

    if(head == NULL)
        return;

    if(k == 1) {

        Node* newNode = new Node(x);

        newNode->next = head;
        head->prev = newNode;

        head = newNode;

        return;
    }

    Node* temp = head;

    for(int i = 1; i < k && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
        return;

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
    Node* fourth = new Node(40);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    insertBeforeKth(head, 3, 25);

    printList(head);

    return 0;
}