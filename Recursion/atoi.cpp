#include<bits/stdc++.h>
using namespace std;

long long solve(string &s, int idx, long long num){
    if(idx>=s.size()) return num;
    num = num*10 + (s[idx]-'0');
    return solve(s, idx+1, num);
}

int myAtoi(string s){
    int n = s.size();
    int i=0;
    while(i<n && s[i]==' ') i++;
    if(i==n) return 0;

    int sign = 1;
    if(s[i]=='-') sign = -1, i++;
    else if(s[i]=='+') i++;

    long long num = solve(s, i, 0);
    num *= sign;

    if(num>INT_MAX) return INT_MAX;
    if(num<INT_MIN) return INT_MIN;
    return (int)num;
}

int main(){
    string s="   -42";
    cout<<myAtoi(s)<<endl;
    return 0;
}