#include <bits/stdc++.h>
using namespace std;

int countSubstrings(string s) {
    int n = s.size();

    return n * (n + 1) / 2;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    int result = countSubstrings(s);

    cout << "Number of substrings = " << result << endl;

    return 0;
}