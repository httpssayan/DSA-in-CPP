#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
    Node(int data,Node* next,Node* prev){
        this->data=data;
        this->next=next;
        this->prev=prev;
    }
};
class Solution{
    public:
    Node* reverse_DLL(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* temp=curr->next;
            curr->next=prev;
            curr->prev=temp;
            prev=curr;
            curr=temp;
    }
        return prev;
    }
};
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->prev=head;
    head->next->next=new Node(3);
    head->next->next->prev=head->next;
    head->next->next->next=new Node(4);
    head->next->next->next->prev=head->next->next;
    Solution ob;
    Node* newHead=ob.reverse_DLL(head);
    while(newHead!=NULL){
        cout<<newHead->data<<" ";
        newHead=newHead->next;
    }
    return 0;
}