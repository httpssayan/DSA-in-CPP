#include<bits/stdc++.h>
using namespace std;

int min_Bit_flips(int start, int goal){
    int count = 0;
   int x=start^goal;
    while(x>0){
        count+=(x&1);
        x=x>>1;
    }
    return count;
}

int main(){
    int start=10,goal=7;
    cout<<min_Bit_flips(start,goal);
    return 0;
}