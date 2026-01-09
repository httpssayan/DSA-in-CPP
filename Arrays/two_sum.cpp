#include <bits/stdc++.h>
using namespace std;
vector <int> twoSum(vector<int>& nums, int target){
    vector <pair<int,int>> v;
    int n = nums.size();
    for(int i=0;i<n;i++){
        v.push_back({nums[i],i});
    }
    sort(v.begin(),v.end());
    int left = 0, right = n-1;
    while(left<right){
        int sum = v[left].first + v[right].first;
        if(sum == target){
            return {v[left].second, v[right].second};
        }
        else if(sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return{-1,-1};
}
int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    cout << "Indices: " << result[0] << ", " << result[1] << endl;
    return 0;
}