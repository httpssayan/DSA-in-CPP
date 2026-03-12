#include<bits/stdc++.h>
using namespace std;
string prefix_to_infix(string s){
    stack<string> st;
    int n=s.length();
    for(int i=n-1;i>=0;i--){
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else{
            string op1=st.top(); st.pop();
            string op2=st.top(); st.pop();
            string temp="("+op1+s[i]+op2+")";
            st.push(temp);
        }
    }
    return st.top();
}
int main(){
    string s="*+AB-CD";
    cout<<prefix_to_infix(s)<<endl;
    return 0;
}