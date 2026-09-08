#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int max_depth(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(max_depth(root->left), max_depth(root->right));
}

int main()
{
    /*
            3
           / \
          9   20
             / \
            15  7
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Depth: " << max_depth(root);

    return 0;
}