#include<bits/stdc++.h>
using namespace std;

int xor_till_n(int n)
{
    if(n % 4 == 0)
        return n;
    else if(n % 4 == 1)
        return 1;
    else if(n % 4 == 2)
        return n + 1;
    else
        return 0;
}

int find_range_xor(int l, int r)
{
    return xor_till_n(r) ^ xor_till_n(l - 1);
}

int main()
{
    int l = 3, r = 9;
    cout << "XOR from " << l << " to " << r << " is: " << find_range_xor(l, r) << endl;
    return 0;
}