#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp){
    if(s.empty() || temp >=s.top()){
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sortStack(stack<int> &s){
    if(!s.empty()){
        int temp=s.top();
        s.pop();
        sortStack(s);
        insert(s,temp);
    }
}
int main(){
    stack<int> s;
    s.push(30);
    s.push(-5);
    s.push(18);
    s.push(14);
    s.push(-3);

    sortStack(s);

    cout << "Sorted numbers are:\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}