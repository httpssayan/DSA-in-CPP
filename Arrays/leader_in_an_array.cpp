#include <bits/stdc++.h>
using namespace std;
vector <int> leader(vector<int>& arr){
    int n=arr.size();
    vector<int> result;
    int max=arr[n-1];
    result.push_back(max);

    for(int i=n-2;i>=0;i--){
        if (arr[i]>max){
            max=arr[i];
            result.push_back(max);
        }
    }
    reverse(result.begin(),result.end());
    if(result.empty()){
        result.push_back(-1);
    }
    return result;
}
int main(){
    vector<int> arr={16,17,4,3,5,2};
    vector<int> ans=leader(arr);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}