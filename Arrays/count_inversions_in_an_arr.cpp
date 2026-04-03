#include<bits/stdc++.h>
using namespace std;

long long merge_and_count(vector<int>& arr, int left, int mid, int right) {
    vector <int> temp;
    int i = left, j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            count += (mid - i + 1); // Count inversions
            j++;
        }
    }

    while (j<=right){
        temp.push_back(arr[j]);
        j++;
    }
    while (i<=mid){
        temp.push_back(arr[i]);
        i++;
    }

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
    return count;
}

long long merge_sort_and_count(vector<int>& arr, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        count += merge_sort_and_count(arr, left, mid);
        count += merge_sort_and_count(arr, mid + 1, right);

        count += merge_and_count(arr, left, mid, right);
    }
    return count;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long inversion_count = merge_sort_and_count(arr, 0, n - 1);
    cout << "Number of inversions: " << inversion_count << endl;

    return 0;
}