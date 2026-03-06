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
    Node* sort012(Node*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node*zeroHead=new Node(-1);
        Node*zeroTail=zeroHead; 
        Node*oneHead=new Node(-1);
        Node*oneTail=oneHead;
        Node*twoHead=new Node(-1);
        Node*twoTail=twoHead;
        Node*curr=head;
        while(curr!=NULL){
            if(curr->data==0){
                zeroTail->next=curr;
                zeroTail=curr;
            }
            else if(curr->data==1){
                oneTail->next=curr;
                oneTail=curr;
            }
            else{
                twoTail->next=curr;
                twoTail=curr;
            }
            curr=curr->next;
        }
        oneTail->next=twoHead->next;
        zeroTail->next=oneHead->next;
        twoTail->next=NULL;
        return zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
    }
};
int main(){
    Node*head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(0);
    head->next->next->next=new Node(1);
    head->next->next->next->next=new Node(2);
    head->next->next->next->next->next=new Node(0);

    Solution s;
    Node*sortedHead=s.sort012(head);
    Node*curr=sortedHead;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    return 0;
}