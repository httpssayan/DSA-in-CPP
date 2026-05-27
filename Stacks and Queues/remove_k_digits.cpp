#include<bits/stdc++.h>
using namespace std;

string remove_k_digits(string num, int k){
    stack<char> s;
    for(char x: num){
        while(!s.empty() && s.top()>x && k>0){
            s.pop();
            k--;
        }
        s.push(x);
    }
    while(k>0 && !s.empty()){
        s.pop();
        k--;
    }

    string ans="";
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    reverse(ans.begin(), ans.end());

    int i=0;
    while(i<ans.size() && ans[i]=='0'){
        i++;
    }
    if(i==ans.size()){
        return "0";
    }
    return ans.substr(i);
}

int main(){
    string num;
    int k;
    cin>>num>>k;
    cout<<remove_k_digits(num, k)<<endl;
}