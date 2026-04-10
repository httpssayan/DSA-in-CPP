#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector <int> &arr, int maxSum){
    int partitions = 1;
    int currentSum = 0;

    for(int num : arr){
        if(currentSum + num > maxSum){
            partitions++;
            currentSum = num;
        } else {
            currentSum += num;
        }
    }
    return partitions;
}

int splitArray(vector <int> &arr, int m){
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = high;

    while(low <= high){
        int mid = low + (high - low) / 2;
        int partitions = countPartitions(arr, mid);

        if(partitions <= m){
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {7, 2, 5, 10, 8};
    int m = 2;
    cout << splitArray(arr, m) << endl; // Output: 18
    return 0;
}