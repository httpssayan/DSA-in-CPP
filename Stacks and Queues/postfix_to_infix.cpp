#include<bits/stdc++.h>
using namespace std;
string postfix_to_infix(string s){
    int n = s.size();
    stack<string> st;
    for(int i=0;i<n;i++){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = "("+op2+s[i]+op1+")";
            st.push(temp);
        }
    }
    return st.top();
}
int main(){
    string s = "ab+cde+**";
    cout<<postfix_to_infix(s)<<endl;
    return 0;
}