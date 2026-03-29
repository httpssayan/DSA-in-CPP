#include<bits/stdc++.h>
using namespace std;

int countSubarrays(vector <int>& arr, int k){
    unordered_map <int,int> mp;
    mp[0]=1;

    int XR=0;
    int count=0;

    for(int num:arr){
        XR^=num;

        int target=XR^k;

        if(mp.find(target)!=mp.end()){
            count+=mp[target];
        }

        mp[XR]++;
    }
    return count;
}
int main() {
    vector<int> A = {4, 2, 2, 6, 4};
    int k = 6;
    
    cout << countSubarrays(A, k) << endl;
    return 0;
}