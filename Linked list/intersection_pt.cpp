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
    Node* intersection_pt(Node* head1, Node* head2){
        Node* ptr1=head1;
        Node* ptr2=head2;
        while (ptr1!=ptr2){
            if(ptr1 == NULL) ptr1=head2;
            else ptr1=ptr1->next;
            if(ptr2 == NULL) ptr2=head1;
            else ptr2=ptr2->next;
        }
        return ptr1;
    }
};
int main(){
    Node* head1=new Node(1);
    head1->next=new Node(2);
    head1->next->next=new Node(3);
    head1->next->next->next=new Node(4);
    head1->next->next->next->next=new Node(5);

    Node* head2=new Node(6);
    head2->next=head1->next->next;

    Solution sol;
    Node* intersection=sol.intersection_pt(head1,head2);
    if(intersection!=NULL){
        cout<<"Intersection point: "<<intersection->data<<endl;
    }else{
        cout<<"No intersection point."<<endl;
    }
    return 0;
}