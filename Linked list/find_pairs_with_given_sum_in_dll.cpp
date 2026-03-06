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
    vector<pair<int,int>> findPairs(Node* head, int target){
        vector<pair<int,int>> ans;
        Node* left=head;
        Node* right=head;
        while(right->next!=NULL){
            right=right->next;
        }
        while(left!=right && right->next!=left){
            int sum=left->data+right->data;
            if(sum==target){
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(sum<target){
                left=left->next;
            }
            else{
                right=right->prev;
            }
        }
        return ans;
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
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->prev=head->next->next->next;
    int target=5;
    Solution sol;
    vector<pair<int,int>> ans=sol.findPairs(head,target);
    for(auto p:ans){
        cout<<'('<<p.first<<","<<p.second<<')'<<endl;
    }
    return 0;
}