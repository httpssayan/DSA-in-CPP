#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int left_ht(TreeNode* root) {
    int ht = 0;
    while (root) {
        ht++;
        root = root->left;
    }
    return ht;
}

int right_ht(TreeNode* root) {
    int ht = 0;
    while (root) {
        ht++;
        root = root->right;
    }
    return ht;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    int lh = left_ht(root);
    int rh = right_ht(root);
    if (lh == rh) {
        return (1 << lh) - 1; // 2^lh - 1
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    cout << "Number of nodes in the complete binary tree: " << countNodes(root) << endl;

    return 0;
}