#include<bits/stdc++.h>
using namespace std;

int preference(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    else return -1;
}

void Infix_to_postfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])) res+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(st.top()!='(' && !st.empty()){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && preference(st.top())>=preference(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    cout<<res;
}
int main(){
    string exp="a+b*(c^d-e)^(f+g*h)-i";
    Infix_to_postfix(exp);
    return 0;
}