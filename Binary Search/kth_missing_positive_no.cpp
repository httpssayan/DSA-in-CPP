#include<bits/stdc++.h>
using namespace std;

int Kth_missing_no(vector<int>  &arr,int k){
    int n = arr.size();
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int missing_count = arr[mid] - (mid + 1);
        
        if (missing_count < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return low + k;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout << "The " << k << "th missing number is: " << Kth_missing_no(arr, k) << endl;
    return 0;
}