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
    Node* deletionAtHead(Node*head){
        if(head==NULL){
            return NULL;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
        return head;
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
    head=s.deletionAtHead(head);
    cout<<"List after deletion at head: ";
    s.printList(head);
    return 0;
}