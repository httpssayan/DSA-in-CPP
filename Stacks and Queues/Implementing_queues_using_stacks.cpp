#include <bits/stdc++.h>
using namespace std;

class Queue_using_stack{
    private:
    stack <int> s1,s2;

    public:

    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        if(s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek(){
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        if(s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        return s2.top();
    }

    bool empty(){
        return s1.empty() && s2.empty();
    }
};

int main(){
    Queue_using_stack q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.peek()<<endl; // Output: 1
    cout<<q.pop()<<endl;  // Output: 1
    cout<<q.peek()<<endl; // Output: 2
    cout<<q.empty()<<endl; // Output: false

    return 0;
}