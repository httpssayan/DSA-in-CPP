#include <bits/stdc++.h>
using namespace std;
bool armstrong(int n){
    int count=0;
    int temp=n;
    while(temp>0){
        count++;
        temp/=10;
    }
    int tem=n;
    int ld=0;
    int sum=0;
    while(n>0){
        ld=n%10;
        sum+=pow(ld,count);
        n/=10;
    }
    if(sum==tem){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n=153;
    cout << armstrong(n) << endl;
    return 0;
}