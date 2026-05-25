#include<bits/stdc++.h>
using namespace std;

// x << n is equivalent to x * 2^n
// x >> n is equivalent to x / 2^n

int divide(int dividend, int divisor) {

if(dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
}

bool negative = (dividend < 0) ^ (divisor < 0);

long long dividendL = abs((long long)dividend);
long long divisorL = abs((long long)divisor);

long long quotient = 0;
while (dividendL >= divisorL) {
    long long temp = divisorL, multiple = 1;
    while (dividendL >= (temp << 1)) {
        temp <<= 1;
        multiple <<= 1;
    }
    dividendL -= temp;
    quotient += multiple;
}

return negative ? -quotient : quotient;

}

int main() {
    int dividend = 10, divisor = 3;
    cout << divide(dividend, divisor) << endl; 
    return 0;
}