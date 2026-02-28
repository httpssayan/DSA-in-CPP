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
    Node* DeleteAtTail(Node*head){
        if(head==NULL || head->next==NULL){
            delete head;
            return NULL;
        }
        Node*temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
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
    head=s.DeleteAtTail(head);
    cout<<"List after deleting tail: ";
    s.printList(head);
    return 0;
}