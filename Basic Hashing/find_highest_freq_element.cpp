#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    map<char,int> hash;
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;
    }

    int max_freq = 0;
    for(auto it : hash){
        if(it.second > max_freq){
            max_freq = it.second;
        }
    }
    for(auto it : hash){
        if(it.second == max_freq){
            cout <<"Highest frequency character(s): " << it.first << " ";
        }
    }
    return 0;
}