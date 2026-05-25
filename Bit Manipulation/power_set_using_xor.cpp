#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> power_set(vector<int> &ans){
    int n = ans.size();
    vector<vector<int>> res;
    for(int i=0; i<(1<<n); i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                temp.push_back(ans[j]);
            }
        }
        res.push_back(temp);
    }
    return res;
}
int main(){
    vector<int> ans = {1,2,3};
    vector<vector<int>> res = power_set(ans);
    for(auto x : res){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}

