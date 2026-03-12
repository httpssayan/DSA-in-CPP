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
    Node* start;
    Node* end;
    int size;

    public:
    Solution(){
        start = NULL;
        end = NULL;
        size = 0;}

    void push(int x){
        Node* newNode = new Node(x);
        if(start == NULL){
            start = newNode;
            end = newNode;
        }
        else{
            end->next = newNode;
            end = newNode;
        }
        size++;
    }

    void pop(){
        if(start == NULL){
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
    }

    int top(){
        if(start == NULL){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return start->data;
    }

    bool isEmpty(){
        return size == 0;
    }
};

int main(){
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl; // Output: 3
    s.pop();
    cout << s.top() << endl; // Output: 2
    cout << s.isEmpty() << endl; // Output: 0 (false)
    s.pop();
    s.pop();
    cout << s.isEmpty() << endl; // Output: 1 (true)
    return 0;
}