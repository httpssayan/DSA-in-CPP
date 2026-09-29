#include<bits/stdc++.h>
using namespace std;
int myAtoi(string s){
    int i=0, sign=1;
    long long num=0;

    while(i<s.size() && s[i]==' ') i++;

    if(i<s.size() && s[i]=='-'){
        sign=-1;
        i++;
    }
    else if(i<s.size() && s[i]=='+') i++;

    while(i<s.size() && isdigit(s[i])){
        int digit=s[i]-'0';

        if(num>(INT_MAX-digit)/10){
            if(sign==1) return INT_MAX;
            else return INT_MIN;
        }
        num=num*10+digit;
        i++;
    }
    return num*sign;
}

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int ans = myAtoi(s);

    cout << "Integer: " << ans << endl;

    return 0;
}