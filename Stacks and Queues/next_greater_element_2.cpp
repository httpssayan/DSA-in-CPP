#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> next_greater_element_2(vector<int>& arr){
        stack<int> st;
        int n= arr.size();
        vector<int> ans(n);
        for(int i=2*n-1; i>=0; i--){
            int ind= i%n;
            while(!st.empty() && st.top() <=arr[ind]){
                st.pop();
            }
            if(i<n){
                if(st.empty()){
                    ans[ind]= -1;
                }
                else{
                    ans[ind]= st.top();
                }
            }
            st.push(arr[ind]);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {5, 7, 1, 7, 6, 0};
    Solution sol;
    vector<int> ans = sol.next_greater_element_2(nums);

    for (int x : ans) {
        cout << x << " ";
    }
    return 0;
}