#include<bits/stdc++.h>
using namespace std;

long long sum_of_Subarray_ranges(vector<int>& nums){
    int n=nums.size();
    stack<int> s;

    vector<int> prevSmaller(n), nextSmaller(n);
    vector<int> prevGreater(n), nextGreater(n);

    for(int i=0;i<n;i++){
        while(!s.empty() && nums[s.top()]>=nums[i]){
            s.pop();
        }
        prevSmaller[i]=s.empty()?-1:s.top();
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && nums[s.top()]>nums[i]){
            s.pop();
        }
        nextSmaller[i]=s.empty()?n:s.top();
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    for(int i=0;i<n;i++){
        while(!s.empty() && nums[s.top()]<=nums[i]){
            s.pop();
        }
        prevGreater[i]=s.empty()?-1:s.top();
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    for(int i=n-1;i>=0;i--){
        while(!s.empty() && nums[s.top()]<nums[i]){
            s.pop();
        }
        nextGreater[i]=s.empty()?n:s.top();
        s.push(i);
    }

    long long minSum=0, maxSum=0;

    for(int i=0;i<n;i++){
        minSum+=(long long)(i-prevSmaller[i])*(nextSmaller[i]-i)*nums[i];
        maxSum+=(long long)(i-prevGreater[i])*(nextGreater[i]-i)*nums[i];
    }

    return maxSum-minSum;
}

int main(){
    vector<int> nums={1,2,3};
    cout<<sum_of_Subarray_ranges(nums);
    return 0;
}
