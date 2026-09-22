#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1])
            return false;
    }

    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 4, 5};

    if (isSorted(arr))
        cout << "Sorted";
    else
        cout << "Not Sorted";

    return 0;
}