#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int solve(TreeNode*root , int &ans){
    if(root == NULL) return 0;

    int left = max(0,solve(root->left , ans));
    int right = max(0,solve(root->right , ans));
    
    int path = left + right + root->val;

    ans=max(ans , path);

    return max(left , right) + root->val;
}

int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;
    solve(root , ans);
    return ans;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    
    return 0;
}