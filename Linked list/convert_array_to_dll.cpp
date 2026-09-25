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

Node* convert(int arr[], int n){
    if(n==0) return NULL;

    Node* head=new Node(arr[0]);
    Node* temp=head;

    for(int i=1;i<n;i++){
        Node* newNode=new Node(arr[i]);

        temp->next=newNode;
        newNode->prev=temp;

        temp=newNode;
    }
    return head;
}

int main() {

    int arr[] = {10, 20, 30, 40};

    Node* head = convert(arr, 4);

    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}