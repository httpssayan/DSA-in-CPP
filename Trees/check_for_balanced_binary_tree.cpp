#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int checkHeight(TreeNode* root) {
    if (root == NULL) return 0;
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;
    if (abs(leftHeight - rightHeight) > 1) return -1;
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int main()
{
    /*
            3
           / \
          1   2
    */

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(2);

    if (isBalanced(root))
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}