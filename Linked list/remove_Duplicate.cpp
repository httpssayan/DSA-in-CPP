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
    Node* remove_Duplicate(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* curr=head;
        while(curr!=NULL){
            Node* temp=curr;
            while(temp!=NULL && temp->data==curr->data){
                Node* dup=temp;
                temp=temp->next;
                delete dup;
            }
            curr->next=temp;
            if(temp!=NULL){
                temp->prev=curr;
            }
            curr=curr->next;
        }
        return head;
    }
};
int main(){
    Node* head=new Node(1);
    head->next=new Node(1);
    head->next->prev=head;
    head->next->next=new Node(2);
    head->next->next->prev=head->next;
    head->next->next->next=new Node(3);
    head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new Node(3);
    head->next->next->next->next->prev=head->next->next->next;
    Solution ob;
    Node* new_head=ob.remove_Duplicate(head);
    while(new_head!=NULL){
        cout<<new_head->data<<" ";
        new_head=new_head->next;
    }
    return 0;
}