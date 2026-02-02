#include<bits/stdc++.h>
using namespace std;
int binary_search(vector<int> &arr, int key){
    int n=arr.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]<key) low=mid+1;
        else high=mid-1;
        }
        return -1;
}
int main() {
    vector<int> arr={2,3,4,10,40};
    int key=10;
    int result=binary_search(arr,key);
    if(result!=-1){
        cout<<"Element present at index "<<result;
    }
    else{
        cout<<"Element not present";
    }
    return 0;
}
