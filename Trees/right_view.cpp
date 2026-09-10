#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void solve(TreeNode*root , int level, vector<int> &ans){
    if(root == NULL) return;

    if(level == ans.size()){
        ans.push_back(root->val);
    }

    solve(root->right, level+1, ans);
    solve(root->left, level+1, ans);
}
vector<int> right_view(TreeNode* root) {
    vector<int> ans;
    solve(root, 0, ans);
    return ans;
}

int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    vector<int> result = right_view(root);

    for(int x : result)
        cout << x << " ";

    return 0;
}