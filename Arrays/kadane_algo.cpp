#include <bits/stdc++.h>
using namespace std;
int kadane_algo(vector<int> &arr){
    int n=arr.size();
    int sum=0;
    int maximum=INT_MIN;
    int start=0;
    int begin=-1,end=-1;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maximum){
            maximum=sum;
            begin=start;
            end=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    for(int i=begin;i<=end;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return maximum;
}
int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    cout<<kadane_algo(arr);
    return 0;
}