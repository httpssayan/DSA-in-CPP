#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    Node(int data,Node*next=NULL){
        this->data=data;
        this->next=next;
    }
};
class Solution{
    public:
    Node* insertAtHead(Node*head, int data){
        Node*newNode=new Node(data);
        newNode->next=head;
        return newNode;
    }

    void printList(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    Node*head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    cout<<"Original List: ";
    s.printList(head);
    head=s.insertAtHead(head,5);
    cout<<"After Inserting 5 at Head: ";
    s.printList(head);
    return 0;
}