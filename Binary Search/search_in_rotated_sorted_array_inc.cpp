#include<bits/stdc++.h>
using namespace std;
int search_in_rotated_sorted_array_inc(vector<int>& arr, int target){
    int low=0;
    int n=arr.size();
    int high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;}
            if(arr[low]<=arr[mid]){
                if(target<arr[mid] && arr[low]<=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(target>arr[mid] && target<=arr[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
    }
    return -1;
}
int main(){
    vector<int> arr={4,5,6,7,0,1,2};
    int target=0;
    cout<<search_in_rotated_sorted_array_inc(arr,target);
    return 0;
}