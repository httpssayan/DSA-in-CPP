#include<bits/stdc++.h>
using namespace std;
void recursive_insertion_sort(vector <int>& arr, int i,int n){
    if(i==n) return;
    int j=i;
    while(j>0 && arr[j-1]>arr[j]){
        swap(arr[j],arr[j-1]);
        j--;
    }
    recursive_insertion_sort(arr,i+1,n);
}
int main() {
    
    vector<int> arr = {64, 25, 12, 22, 11};
    int n=arr.size();
    recursive_insertion_sort(arr,0,n);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}