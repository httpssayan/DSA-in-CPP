#include<bits/stdc++.h>
using namespace std;
int count_occurences(vector <int>& arr, int target){
    int n=arr.size();
    int low=0, high=n-1, count=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target){
            count++;
            int left=mid-1;
            while(left>=0 && arr[left]==target){
                count++;
                left--;
            }
            int right=mid+1;
            while(right<n && arr[right]==target){
                count++;
                right++;
            }
            return count;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;

        }
    }
    return count;
}
int main(){
    vector<int> arr={1,2,2,2,3,4,5};
    int target=2;
    cout<<count_occurences(arr,target);
    return 0;
}
