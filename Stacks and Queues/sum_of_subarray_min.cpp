#include<bits/stdc++.h>
using namespace std;

int sum_of_subarray_min(vector<int> &arr){
    int n=arr.size();
    vector<int> left(n), right(n);
    stack<int> s;

    for(int i=0; i<n; i++){
        while(!s.empty() && arr[s.top()]>=arr[i]){
            s.pop();
        }
        left[i]=s.empty() ? -1 : s.top();
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    for(int i=n-1; i>=0; i--){
        while(!s.empty() && arr[s.top()]>arr[i]){
            s.pop();
        }
        right[i]=s.empty() ? n : s.top();
        s.push(i);
    }

    long long sum=0;

    int mod=1e9+7;

    for(int i=0; i<n; i++){
        sum=(sum + (long long)arr[i]*(i-left[i])*(right[i]-i))%mod;
    }
    return sum;
}

int main(){
    vector<int> arr={3,1,2,4};
    cout<<sum_of_subarray_min(arr)<<endl;
    return 0;
}