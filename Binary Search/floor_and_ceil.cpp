#include<bits/stdc++.h>
using namespace std;
int floor(vector<int>& arr, int target){
    int low=0,high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=target){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int ceil(vector<int>& arr, int target){
    int low=0,high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
pair <int,int> get_both(vector<int>& arr,int target){
    int f=floor(arr,target);
    int c=ceil(arr, target);
    return make_pair(f,c);
}
int main() {
    vector<int> arr={1,3,5,7,9};
    int target=6;
    pair<int,int> result=get_both(arr,target);
    cout<<"Floor and ceil index: "<< result.first << " and " << result.second <<endl;
    return 0;
}