#include<bits/stdc++.h>
using namespace std;
class Stack_from_queue{
    queue<int> q;
    public:
    void push(int x){
        q.push(x);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        if(q.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int top=q.front();
        q.pop();
        return top;
    }

    int top(){
        if(q.empty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return q.front();
    }

    bool empty(){
        return q.empty();
    }
};

int main(){
    Stack_from_queue s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.top()<<endl; // Output: 3
    cout<<s.pop()<<endl; // Output: 3
    cout<<s.top()<<endl; // Output: 2
    cout<<s.empty()<<endl; // Output: 0 (false)
    s.pop();
    s.pop();
    cout<<s.empty()<<endl; // Output: 1 (true)
    return 0;
}
