#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insert_at_bottom(s, x);
    s.push(temp);
}
void reverse_stack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse_stack(s);
    insert_at_bottom(s, temp);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    reverse_stack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}