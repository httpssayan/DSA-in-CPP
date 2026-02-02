#include<bits/stdc++.h>
using namespace std;
int last_occ_in_sorted_array(vector<int>& arr, int target){
    int n=arr.size();
    int low=0;
    int high=n-1;
    int res=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            res=mid;
            low=mid+1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;
}
int main() {
    vector<int> arr={1,2,2,2,3,4,5};
    int target=2;
    cout<<last_occ_in_sorted_array(arr,target);
    return 0;
}
