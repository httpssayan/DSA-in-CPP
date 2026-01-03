#include <iostream>
using namespace std;
bool string_is_pallindrome(string &s,int i){
    if (i<s.length()/2){
        return true;
    }
        if (s[i]!=s[s.length()-i-1]){
            return false;
        }
        return string_is_pallindrome(s,i+1);
    
}
int main(){
    string s="malayalam";
    if (string_is_pallindrome(s,0)){
        cout<<"Pallindrome"<<endl;
    }
    else{
        cout<<"Not a Pallindrome"<<endl;
    }
    return 0;
}