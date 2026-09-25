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

void deleteTail(Node* &head){
    if(head==NULL) return ;
    Node* temp=head;

    while(temp->next!=NULL) temp=temp->next;

    if(temp->prev==NULL) {
        head=NULL;
        delete temp;
        return;
    }

    temp->prev->next=NULL;
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

    deleteTail(head);

    printList(head);

    return 0;
}