#include <bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

string infixToPrefix(string s){
    
    reverse(s.begin(), s.end());

    for(int i=0;i<s.size();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }

    stack<char> st;
    string res="";

    for(int i=0;i<s.size();i++){

        if(isalnum(s[i])){
            res+=s[i];
        }

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && precedence(st.top())>precedence(s[i])){
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

    reverse(res.begin(), res.end());

    return res;
}

int main(){
    string s="(A+B)*C";
    cout<<infixToPrefix(s);
}