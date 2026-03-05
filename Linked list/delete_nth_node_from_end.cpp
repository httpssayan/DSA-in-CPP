#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};

class Solution {
    public:
    Node* delete_nth_node_from_end(Node* head, int n){
        Node* slow= head;
        Node* fast = head;
        for(int i=0; i<n; i++){
            fast = fast->next;
        }
        if(fast == NULL){
            return head->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int n = 2;
    Solution sol;
    head = sol.delete_nth_node_from_end(head, n);
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}