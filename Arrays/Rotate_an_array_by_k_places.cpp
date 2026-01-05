#include <bits/stdc++.h>
using namespace std;
void Reverse_Array(vector<int>& arr, int start, int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}
void Rotate_Array_By_K(vector<int>& arr, int k, int n, string direction){
    k=k%n;
    if(direction=="Right"){
        Reverse_Array(arr,0,n-1);
        Reverse_Array(arr,0,k-1);
        Reverse_Array(arr,k,n-1);
    }
    else if(direction=="Left"){
        k=n-k;
        Reverse_Array(arr,0,n-1);
        Reverse_Array(arr,0,k-1);
        Reverse_Array(arr,k,n-1);
    }
}
int main(){
    vector<int> arr={1,2,3,4,5};
    int k=2;
    int n=arr.size();
    string direction="Left";
    Rotate_Array_By_K(arr,k,n,direction);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}