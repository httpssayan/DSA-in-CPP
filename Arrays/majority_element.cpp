#include <bits/stdc++.h>
using namespace std;
int majority_element(vector<int> &nums){
    int n= nums.size();
    int count=0;
    int element;
    for(int num:nums){
        if(count==0){
            count=1;
            element=num;
        }
        else if(element==num){
            count++;
        }
        else{
            count--;
        }
    }
    int count1=0;
    for(int num:nums){
        if(num==element){
            count1++;
        }
    }
    if(count1>n/2){
        return element;
    }
    return -1;
}
int main(){
    vector<int> nums={2,2,1,1,1,2,2};
    cout<<majority_element(nums);
    return 0;
}