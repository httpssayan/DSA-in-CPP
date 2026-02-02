#include<bits/stdc++.h>
using namespace std;
int calculate_total_hours(vector<int> &arr, int speed){
    int h=0;
    for(int i=0;i<arr.size();i++){
        h+=ceil((double)arr[i]/speed);
    }
    return h;
}
int koko_eating_bananas(vector<int> &arr, int h){
    int low=1, high=*max_element(arr.begin(), arr.end());
    int ans=-1;
    while(low<high){
        int mid=(low+high)/2;
        int total_hours=calculate_total_hours(arr, mid);
        if(total_hours<=h){
            ans=mid;
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> arr={3,6,7,11};
    int h=8;
    cout<<koko_eating_bananas(arr, h);
    return 0;
}