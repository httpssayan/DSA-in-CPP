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
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node* addOne(Node* head){

    head = reverse(head);

    Node* temp = head;
    int carry = 1;

    while(temp != NULL){
        temp->data += carry;

        if(temp->data < 10){
            carry = 0;
            break;
        }

        temp->data = 0;
        carry = 1;

        if(temp->next == NULL)
            temp->next = new Node(0);

        temp = temp->next;
    }

    head = reverse(head);

    return head;
}
};
int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    Solution s;
    Node* result=s.addOne(head);
    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }
    return 0;
}