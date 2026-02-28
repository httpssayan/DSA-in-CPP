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
    Node* find_mid(Node* head){
        if(head==NULL) return NULL;
        Node*slow=head;
        Node*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main(){
    Solution s;
    Node*head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    cout<<s.find_mid(head)->data<<endl;
}