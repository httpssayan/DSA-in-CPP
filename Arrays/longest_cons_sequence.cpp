#include <bits/stdc++.h>
using namespace std;
int longest_cons_seq(vector<int> &arr){
    int n=arr.size();
    vector<int> result(n);
    int count=0;
    int longest=1;
    sort(arr.begin(),arr.end());
    int min=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1==min){
            count++;
            min=arr[i];
        }
        else if(arr[i]!=min){
            count=1;
            min=arr[i];
        }
        longest=max(longest,count);
    }
    return longest;
}
int main(){
    vector<int> arr={100,4,200,1,3,2};
    cout<<longest_cons_seq(arr);
    return 0;
}