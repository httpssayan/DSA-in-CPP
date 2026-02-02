#include<bits/stdc++.h>
using namespace std;
int largest_subarray(vector<int> arr,int k){
    int n=arr.size();
    int max_len=0;
    int left=0,right=0;
    int sum=arr[0];
    while(right<n){
        if(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if (sum==k){
            max_len=max(max_len,right-left+1);
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    return max_len;
}
int main(){
    vector<int> arr={1,2,3,7,5};
    int k=12;
    cout<<largest_subarray(arr,k);
    return 0;
}