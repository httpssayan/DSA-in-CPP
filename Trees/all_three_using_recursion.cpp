#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void PreOrder(TreeNode* root, vector<int> & ans){
    if (root == NULL) return;
    ans.push_back(root->val);
    PreOrder(root->left, ans);
    PreOrder(root->right, ans);
}

void InOrder(TreeNode* root, vector<int> & ans){
    if (root == NULL) return;
    InOrder(root->left, ans);
    ans.push_back(root->val);
    InOrder(root->right, ans);
}

void PostOrder(TreeNode* root, vector<int> & ans){
    if (root == NULL) return;
    PostOrder(root->left, ans);
    PostOrder(root->right, ans);
    ans.push_back(root->val);
}

int main()
{
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(9);
    root->left->left->right->left = new TreeNode(1);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(8);

    vector<int> pre, in, post;

    PreOrder(root, pre);
    InOrder(root, in);
    PostOrder(root, post);

    cout << "Preorder: ";
    for (int x : pre)
        cout << x << " ";

    cout << "\nInorder: ";
    for (int x : in)
        cout << x << " ";

    cout << "\nPostorder: ";
    for (int x : post)
        cout << x << " ";

    return 0;
}