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

void deleteKth(Node*& head, int k) {

    if(head == NULL)
        return;

    Node* temp = head;

    for(int i = 1; i < k && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
        return;

    if(temp->prev == NULL) {

        head = temp->next;

        if(head)
            head->prev = NULL;

        delete temp;
        return;
    }

    temp->prev->next = temp->next;

    if(temp->next)
        temp->next->prev = temp->prev;

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
    Node* fourth = new Node(40);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    deleteKth(head, 3);

    printList(head);

    return 0;
}