#include<bits/stdc++.h>
using namespace std;

int len_of_longest_subarray_with_0_sum(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> mp;
    int sum = 0, max_len = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];

        if(sum==0){
            max_len = i+1;
        }

        if(mp.find(sum) != mp.end()){
            max_len = max(max_len, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }
    return max_len;
}

int main() {
    vector<int> arr = {1, -1, 3, 2, -2, -3, 3};
    cout << "Length of longest subarray with sum 0: " << len_of_longest_subarray_with_0_sum(arr) << endl;
    return 0;
}