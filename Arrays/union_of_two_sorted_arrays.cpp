#include <bits/stdc++.h>
using namespace std;

vector<int> union_of_two_sorted_arrays(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;
    vector<int> unionArr;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr1[i])
                unionArr.push_back(arr1[i]);
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            if (unionArr.empty() || unionArr.back() != arr2[j])
                unionArr.push_back(arr2[j]);
            j++;
        }
        else {
            if (unionArr.empty() || unionArr.back() != arr1[i])
                unionArr.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    while (i < n) {
        if (unionArr.empty() || unionArr.back() != arr1[i])
            unionArr.push_back(arr1[i]);
        i++;
    }

    while (j < m) {
        if (unionArr.empty() || unionArr.back() != arr2[j])
            unionArr.push_back(arr2[j]);
        j++;
    }

    return unionArr;
}

int main() {
    int arr1[] = {1,2,2,3,4};
    int arr2[] = {2,3,5,6};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    vector<int> uni = union_of_two_sorted_arrays(arr1, arr2, n, m);

    for (int x : uni)
        cout << x << " ";

    return 0;
}
