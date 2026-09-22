#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 12;
    int b = 18;

    int gcd = __gcd(a, b);
    int lcm = (a / gcd) * b;

    cout << lcm;

    return 0;
}