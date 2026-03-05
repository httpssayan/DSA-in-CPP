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
    Node*get_mid(Node*head){
        Node*slow=head;
        Node*fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    Node*merge(Node*left,Node*right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        Node*ans=new Node(-1);
        Node*temp=ans;
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                temp->next=left;
                temp=temp->next;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=temp->next;
                right=right->next;
            }
        }
        if(left!=NULL){
            temp->next=left;
        }
        if(right!=NULL){
            temp->next=right;
        }
        return ans->next;
    }

    Node* sort_ll(Node*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node*mid=get_mid(head);
        Node*right=mid->next;
        mid->next=NULL;
        Node*left=head;
        left=sort_ll(left);
        right=sort_ll(right);
        return merge(left,right);
    }
};
int main(){
    Node*head=new Node(4);
    head->next=new Node(2);
    head->next->next=new Node(1);
    head->next->next->next=new Node(3);
    Solution s;
    head=s.sort_ll(head);
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}