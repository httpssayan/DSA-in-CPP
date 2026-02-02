#include <bits/stdc++.h>
using namespace std;
void Insertion_Sort(vector<int>& arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
} 
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    Insertion_Sort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}