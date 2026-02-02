#include<bits/stdc++.h>
using namespace std;
int peak_element(vector<int> &arr){
    int low=0, high=arr.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}
int main(){
    vector<int> arr={1,3,20,4,1,0};
    int peakIndex=peak_element(arr);
    cout<<"Peak element is at index: "<<peakIndex<<", Value: "<<arr[peakIndex]<<endl;
    return 0;
}