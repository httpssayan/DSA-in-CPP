#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool StringsAreEqual(string str1, string str2) {
        return str1 == str2;
    }
};
int main(){
    Solution sol;
    string str1 = "hello";
    string str2 = "hello";
    if (sol.StringsAreEqual(str1, str2)) {
        cout << "The strings are equal." << endl;
    } else {
        cout << "The strings are not equal." << endl;
    }
    return 0;
}