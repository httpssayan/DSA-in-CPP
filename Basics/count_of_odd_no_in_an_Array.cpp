#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 7};

    int count = 0;

    for (int x : arr) {
        if (x % 2 != 0)
            count++;
    }

    cout << count;

    return 0;
}