#include <bits/stdc++.h>
using namespace std;
void move_zeroes_to_end(vector<int> & arr,int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}
int main(){
    vector<int> arr={1,2,0,3,0,0,4,5};
    int n=arr.size();
    move_zeroes_to_end(arr,n);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}