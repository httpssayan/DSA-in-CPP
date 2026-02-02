#include <bits/stdc++.h>
using namespace std;
void Left_Rotate_Array_By_One(vector<int>& nums) {
        int i=0;
        int temp=nums[0];
        int n=nums.size();
        for(int j=1;j<n;j++){
            nums[i]=nums[j];
            i++;
            }
            nums[n-1]=temp;
        };
int main(){
    vector<int> arr={1,2,3,4,5};
    Left_Rotate_Array_By_One(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}