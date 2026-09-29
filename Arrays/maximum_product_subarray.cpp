#include<bits/stdc++.h>
using namespace std;

int max_prod_subarray(vector<int> &nums){
    int mx=nums[0], mn=nums[0], ans=nums[0];

    for(int i=0;i<nums.size();i++){
        int x=nums[i];
        int old=mx;

        mx=max({x,mx*x,mn*x});
        mn=min({x,old*x,mn*x});

        ans=max(mx,ans);
    }
    return ans;
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = max_prod_subarray(arr);

    cout << "Maximum product subarray = " << ans << endl;

    return 0;
}