#include <bits/stdc++.h>
using namespace std;
void recursive_bubble_sort(vector<int>& arr, int n){
    
    if(n==1) return;
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
    }
    recursive_bubble_sort(arr,n-1);
}
int main() {
    
    vector<int> arr = {64, 25, 12, 22, 11};
    int n=arr.size();
    recursive_bubble_sort(arr,n);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}