#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> next_smaller_element(vector<int>& arr){
        stack<int> st;
        int n= arr.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() >=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {4, 5, 2, 10};
    Solution sol;
    vector<int> ans = sol.next_smaller_element(nums);

    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}