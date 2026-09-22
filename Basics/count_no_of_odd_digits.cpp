#include<bits/stdc++.h>
using namespace std;

int count_no_of_odd_digits(int n){
    int c=0;
    while(n>0){
        int d=n%10;
        if(d%2!=0) c++;
        n=n/10;
    }
    return c;
}

int main() {
    int n = 1234567;

    cout << count_no_of_odd_digits(n);

    return 0;
}