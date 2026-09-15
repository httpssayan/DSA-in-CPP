#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* search_in_bst(TreeNode* root, int val){
    if(!root) return NULL;

    if(root->val == val) return root;

    if(val < root->val) return search_in_bst(root->left, val);
    else return search_in_bst(root->right, val);
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int val = 2;
    TreeNode* result = search_in_bst(root, val);
    if(result) cout << "Found: " << result->val << endl;
    else cout << "Not Found" << endl;

    return 0;
}