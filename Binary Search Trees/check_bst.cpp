#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode* root, int low, int high){
    if(root==NULL) return true;

    if(root->val<=low || root->val>=high){
        return false;
    }

    return check(root->left,low,root->val) && check(root->right,root->val,high);
}

bool isValidBST(TreeNode* root){
    return check(root,INT_MIN,INT_MAX);
}

int main() {

    // Create a valid BST
    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    /*
              8
            /   \
           3     12
          / \    / \
         1   6  10  14
    */

    if (isValidBST(root))
        cout << "It is a valid BST" << endl;
    else
        cout << "It is NOT a valid BST" << endl;

    return 0;
}