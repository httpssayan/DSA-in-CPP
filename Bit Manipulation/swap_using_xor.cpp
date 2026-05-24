#include<bits/stdc++.h>
using namespace std;

int main(){
    int x=5;
    int y=6;
    x=x^y; 
    y=x^y;
    x=x^y;
    cout<<x<<" "<<y;
     return 0;
}