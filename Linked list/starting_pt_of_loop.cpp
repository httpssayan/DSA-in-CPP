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

class Solution{
    public:
        Node* detect_a_cycle(Node* head){
        if(head == NULL) return NULL;
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow=head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            };
        }
        return NULL;
}

};
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head;
    Solution s;
    Node* res = s.detect_a_cycle(head);
    if(res != NULL){
        cout<<res->data;
    }
else{
        cout<<"No cycle detected";
    }
    return 0;
}