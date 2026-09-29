#include <bits/stdc++.h>
using namespace std;

string reverseString(string s) {
    int left = 0;
    int right = s.size() - 1;

    while(left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }

    return s;
}

int main() {
    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = reverseString(s);

    cout << "Reversed string = " << result << endl;

    return 0;
}