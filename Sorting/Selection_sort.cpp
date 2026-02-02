#include <bits/stdc++.h>
using namespace std;
void Selection_Sort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int min=i;
        for (int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}   
int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    Selection_Sort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}