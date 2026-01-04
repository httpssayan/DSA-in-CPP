#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    map<char,int> hash;
    for(int i=0;i<s.size();i++){
        hash[s[i]-'a']++;
    }

    int q;
    cin>>q;
    while(q--){
        char c;
        cin>>c;
        cout<<hash[c-'a']<<endl;
    }
    return 0;
}