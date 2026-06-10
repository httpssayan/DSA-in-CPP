#include<bits/stdc++.h>
using namespace std;

double solve(double x, long long n){
    if(n==0) return 1;
    double half=solve(x, n/2);
    if(n%2==0) return half*half;
    else return half*half*x;
}
double myPow(double x, int n) {
    if(n<0) return 1/solve(x, -n);
    else return solve(x, n);
}

int main(){
    double x; int n;
    cin>>x>>n;
    cout<<myPow(x, n)<<endl;
    return 0;
}