#include<bits/stdc++.h>
using namespace std;

int subarray_count(vector<int> &arr, int k){
    unordered_map<int, int> mp;
    int count = 0;
    int sum = 0;
    mp[0] = 1; 

    for(int x : arr){
        sum += x;
        if(mp.find(sum - k) != mp.end()){
            count += mp[sum - k];
        }
        mp[sum]++;
    }
    return count;
}

int main(){
    vector<int> arr = {1, 2, 3, -2, 5};
    int k = 5;
    cout << subarray_count(arr, k) << endl; 
    return 0;
}