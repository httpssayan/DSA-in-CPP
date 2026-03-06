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
    Node* Add_two_no_in_a_ll(Node*head1, Node*head2){
        Node*dummy=new Node(-1);
        Node*temp=dummy;
        int carry=0;
        while(head1!=NULL || head2!=NULL || carry){
            int sum=carry;
            if(head1!=NULL){
                sum+=head1->data;
                head1=head1->next;
            }
            if(head2!=NULL){
                sum+=head2->data;
                head2=head2->next;
            }
            carry=sum/10;
            temp->next=new Node(sum%10);
            temp=temp->next;
        }
        return dummy->next;
    }

};
int main(){
    Node*head1=new Node(2);
    head1->next=new Node(4);
    head1->next->next=new Node(3);

    Node*head2=new Node(5);
    head2->next=new Node(6);
    head2->next->next=new Node(4);

    Solution s;
    Node*result=s.Add_two_no_in_a_ll(head1,head2);
    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }
    return 0;
}
