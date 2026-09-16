#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build(vector<int>& preorder, int &i, long long low, long long high){
    if(i==preorder.size()) return NULL;

    int value=preorder[i];

    if(value<=low || value>=high) return NULL;

    TreeNode* root= new TreeNode(value);
    i++;

    root->left=build(preorder, i, low, value);
    root->right=build(preorder, i, value, high);

    return root;
}

TreeNode* bst_from_preorder(vector<int> &preorder){
    int index=0;
    return build(preorder,index,LLONG_MIN,LLONG_MAX);
}

void inorder(TreeNode* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    int index = 0;

    TreeNode* root = build(preorder, index, LLONG_MIN, LLONG_MAX);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}