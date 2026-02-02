#include<bits/stdc++.h>
using namespace std;
string remove_outer_parentheses(string s){
    string result;
    int level=0;
    for(int i=0;i<s.size();i++){
        if (s[i]=='('){
            if(level>0){
                result+=s[i];
            }
            level++;
        }else{
            level--;
            if(level>0){
                result+=s[i];
            }
        }
    }
    return result;
}
int main(){
    string s="(()())(())(()(()))";
    cout<<remove_outer_parentheses(s)<<endl;
    return 0;
}