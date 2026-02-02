#include<bits/stdc++.h>
using namespace std;
int times_array_is_rotated(vector<int>& arr){
    int low=0, high=arr.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(arr[mid]>arr[high]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}
int main(){
    vector<int> arr={4,5,6,7,0,1,2};
    cout<<times_array_is_rotated(arr);
    return 0;
}