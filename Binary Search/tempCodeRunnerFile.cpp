#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int>& arr, int mid, int m, int k){
    int n=arr.size();
    int count=0;
    int bouquets=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=mid){
            count++;
            if(count==k){
                bouquets++;
                count=0;
            }
        }
        else{
            count=0;
        }
    }
    return bouquets>=m;
}
int min_days_to_make_m_bouquets(vector<int>& arr, int m, int k){
    int n = arr.size();
    if(m * k > n) return -1;
    int low=*min_element(arr.begin(), arr.end());
    int high=*max_element(arr.begin(), arr.end());
    int res=-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(possible(arr, mid, m, k)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int main(){
    vector<int> arr = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout << min_days_to_make_m_bouquets(arr, m, k) << endl;
    return 0;
}