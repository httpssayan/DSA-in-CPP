#include<bits/stdc++.h>
using namespace std;
int find_the_smallest_divisor(vector<int>& arr, int threshold){
    int n=arr.size();
    if(n>threshold) return -1;
    int left=1, right=*max_element(arr.begin(), arr.end());
    int res;
    while(left<=right){
        int mid=(left+right)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)arr[i]/mid);
        }
        if(sum<=threshold){
            res=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return res;
}
int main(){
    vector<int> arr={1,2,5,9};
    int threshold=6;
    cout<<find_the_smallest_divisor(arr, threshold)<<endl;
    return 0;
}