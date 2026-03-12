#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    bool balanced_parenthesis(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char top = st.top();
                st.pop();
                if((s[i] == ')' && top != '(') || (s[i] == '}' && top != '{') || (s[i] == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = "{[()]}";
    if(sol.balanced_parenthesis(s)) {
        cout << "Balanced Parenthesis" << endl;
    } else {
        cout << "Not Balanced Parenthesis" << endl;
    }
    return 0;
}