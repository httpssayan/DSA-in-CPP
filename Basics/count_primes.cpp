#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int count_primes(int n){
    int c=0;

    for(int i=2;i<n;i++){
        if(isPrime(i)) c++;
    }
    return c;
}

int main() {
    int n = 20;

    cout << count_primes(n);

    return 0;
}