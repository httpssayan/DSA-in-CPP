#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> four_sum(vector<int> nums, int target){
    int n=nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;

        for(int j=i+1;j<n;j++){
            if(j>0 && nums[j]==nums[j-1]) continue;

            int left=j+1, right=n-1;

            while(left<right){
                long long sum=(long long) nums[i]+nums[j]+nums[left]+nums[right];

                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[left],nums[right]}),left++,right--;

                    while(left< right && nums[left]== nums[left-1]) left++;
                while(left<right && nums[right]==nums[right+1]) right--;
                }
                else if(sum<target) left++;
                else right--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector<vector<int>> ans = four_sum(arr, target);

    for (auto quad : ans) {
        for (int num : quad) cout << num << " ";
        cout << endl;
    }
    return 0;
}