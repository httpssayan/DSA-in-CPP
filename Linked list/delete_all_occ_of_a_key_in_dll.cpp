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
    Node* deleteAllOccurences(Node* head, int key){
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                if(temp==head){
                    head=temp->next;
                }
                Node* nextNode=temp->next;
                Node* prevNode=temp->prev;
                if(prevNode!=NULL){
                    prevNode->next=nextNode;
                }
                if(nextNode!=NULL){
                    nextNode->prev=prevNode;
                }
                delete temp;
                temp=nextNode;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->prev=head;
    head->next->next=new Node(3);
    head->next->next->prev=head->next;
    head->next->next->next=new Node(2);
    head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new Node(4);
    head->next->next->next->next->prev=head->next->next->next;
    int key=2;
    Solution sol;
    head=sol.deleteAllOccurences(head,key);
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}