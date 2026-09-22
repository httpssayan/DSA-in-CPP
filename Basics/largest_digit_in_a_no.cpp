#include<bits/stdc++.h>
using namespace std;

int largest_digit_in_a_no(int n){
    int c=0, maxi=0;
    while(n>0){
        int d=n%10;
        maxi=max(maxi,d);
        n=n/10;
    }
    return maxi;
}

int main() {
    int n = 1234567;

    cout << largest_digit_in_a_no(n);

    return 0;
}