#include <bits/stdc++.h>
using namespace std;

int main(){
    int n=8;
    if(n>1 && (n & (n-1))==0){
        cout<<"Power of 2";
    }
    else{
        cout<<"Not a power of 2";
    }
    return 0;
}