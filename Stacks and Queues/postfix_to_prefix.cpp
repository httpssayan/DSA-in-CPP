#include<bits/stdc++.h>
using namespace std;
string postfix_to_prefix(string s){
    stack<string> st;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = string(1,s[i])+op2+op1;
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string prefix = "AB+C*";
    cout << postfix_to_prefix(prefix) << endl;
    return 0;
}