#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> vertical_trav(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    map<int,vector<int>> mp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int col = p.second;

        mp[col].push_back(node->val);

        if(node->left) q.push({node->left,col-1});
        if(node->right) q.push({node->right,col+1});
    }
    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = vertical_trav(root);

    for(auto vec: result){
        for(int val: vec){
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}