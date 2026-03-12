#include<bits/stdc++.h>
using namespace std;
string prefix_to_postfix(string s){
    stack<string> st;
    int n = s.size();
    for(int i=n-1;i>=0;i--){
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = op1 + op2 + s[i];
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    cout << prefix_to_postfix(prefix) << endl;
    return 0;
}