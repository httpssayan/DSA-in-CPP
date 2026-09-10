#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagTraversal(TreeNode* root){
    vector<vector<int>> result;
    if(!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while(!q.empty()){
        vector<int> level;
        for(int i=0;i<q.size();i++){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(!leftToRight) reverse(level.begin(), level.end());
        result.push_back(level);
        leftToRight = !leftToRight;
    }
    return result;
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = zigzagTraversal(root);

    for(const auto& level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}