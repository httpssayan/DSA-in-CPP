#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find_min(TreeNode* root){
    if(root==NULL) return -1;
    while(root->left!=NULL){
        root=root->left;
    }
    return root->val;
}

int find_max(TreeNode* root){
    if(root==NULL) return -1;
    while(root->right!=NULL){
        root=root->right;
    }
    return root->val;
}

int main() {

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    cout << "Minimum: " << find_min(root) << endl;
    cout << "Maximum: " << find_max(root) << endl;

    return 0;
}