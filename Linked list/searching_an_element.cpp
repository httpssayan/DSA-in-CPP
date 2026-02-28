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
    bool searching_an_element(Node*head, int key){
        Node*temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
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
    cout<<s.searching_an_element(head,20)<<endl;
}