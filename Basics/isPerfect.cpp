#include<bits/stdc++.h>
using namespace std;

bool is_Perfect(int n){
    int sum=0;

    for(int i=1;i<=n/2;i++){
        if(n%i==0) sum+=i;
    }
    return sum==n;
}

int main() {
    int n = 28;

    if (is_Perfect(n))
        cout << "Perfect Number";
    else
        cout << "Not a Perfect Number";

    return 0;
}