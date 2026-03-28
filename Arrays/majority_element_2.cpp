#include<bits/stdc++.h>
using namespace std;

vector<int> majority_element_2(vector <int>& arr){
    int n=arr.size();
    vector<int> ans;

    unordered_map<int,int> mp;

    int min=int(n/3)+1;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;

        if(mp[arr[i]]==min){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    
   
    vector<int> ans = majority_element_2(arr);
    
    cout << "The majority elements are: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << "\n";
    
    return 0;
}