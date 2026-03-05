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
    Node* segregrate_odd_even(Node* head){
        Node* oddhead = NULL;
        Node* oddtail = NULL;
        Node* evenhead = NULL;
        Node* eventail = NULL;

        Node* temp = head;
        while(temp != NULL){
            if(temp->data % 2 !=0){
                if(oddhead == NULL){
                    oddhead=oddtail = temp;
                } else {
                    oddtail->next = temp;
                    oddtail = temp;
                }
            } else {
                if(evenhead == NULL){
                    evenhead=eventail = temp;
                } else {
                    eventail->next = temp;
                    eventail = temp;
                }
            }
            temp = temp->next;
        }
        if(oddhead == NULL){
            return evenhead;
        }
        if(evenhead == NULL){
            return oddhead;
        }
        eventail->next = oddhead;
        oddtail->next = NULL;
        return evenhead;
    }
};
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    Solution sol;
    Node* newHead = sol.segregrate_odd_even(head);

    Node* temp = newHead;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
