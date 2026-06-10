#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9 + 7;

long long power(long long x, long long n){
    if(n==0) return 1;
    long long half = power(x, n/2);
    long long ans = (half * half) % mod;
    if(n%2) ans = (ans * x) % mod;
    return ans;
}

long long countGoodNumber(long long n){
    long long even = (n + 1) / 2;
    long long odd = n / 2;
    return (power(5, even) * power(4, odd)) % mod;
}

int main(){
    long long n;
    cin >> n;
    cout << countGoodNumber(n) << endl;
    return 0;
}