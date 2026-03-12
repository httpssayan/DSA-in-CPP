#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution{
    private:
    Node* head;
    int size;
    public:
    Solution(){
        head = NULL;
        size = 0;}
        void push(int x){
            Node* temp = new Node(x);
            temp->next = head;
            head = temp;
            size++;
        }

        int pop(){
            if(head == NULL){
                return -1;
            }
            int res = head->data;
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return res;
        }

        int top(){
            if(head == NULL){
                return -1;
            }
            return head->data;
        }

        bool isEmpty(){
            return head == NULL;
        }
};
int main(){
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl; // 3
    cout<<s.pop()<<endl; // 3
    cout<<s.top()<<endl; // 2
    cout<<s.isEmpty()<<endl; // 0 (false)
    s.pop();
    s.pop();
    cout<<s.isEmpty()<<endl; // 1 (true)
    return 0;
}