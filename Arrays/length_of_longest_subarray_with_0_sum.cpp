#include<bits/stdc++.h>
using namespace std;

int maxLen(vector <int> &arr){
    int n=arr.size();
    unordered_map<int, int> mp;
    int maxl=0;
    int sum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum==0){
            maxl=i+1;
        }

        else {
            if(mp.find(sum)!=mp.end()){
                maxl=max(maxl,i-mp[sum]);
            }

            else{
                mp[sum]=i;
            }
        }
    }
    return maxl;
}

int main() {
  // sample input
  vector<int> A = {9, -3, 3, -1, 6, -5};
  // compute size
  // print result
  cout << maxLen(A) << endl;
  // exit
  return 0;
}