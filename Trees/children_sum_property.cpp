#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void changeTree(TreeNode* root) {

    if(root == NULL)
        return;

    int childSum = 0;

    if(root->left)
        childSum += root->left->val;

    if(root->right)
        childSum += root->right->val;

    // If children sum is smaller, increase left child
    // (or right child if left doesn't exist)
    if(childSum < root->val) {

        if(root->left)
            root->left->val = root->val - 
                              (root->right ? root->right->val : 0);

        else if(root->right)
            root->right->val = root->val;
    }

    // Fix children first
    changeTree(root->left);
    changeTree(root->right);

    // Update current node using children's sum
    childSum = 0;

    if(root->left)
        childSum += root->left->val;

    if(root->right)
        childSum += root->right->val;

    if(root->left || root->right)
        root->val = childSum;
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);

    changeTree(root);

    // Output the modified tree (in-order traversal)
    function<void(TreeNode*)> printInOrder = [&](TreeNode* node) {
        if (!node) return;
        printInOrder(node->left);
        cout << node->val << " ";
        printInOrder(node->right);
    };

    printInOrder(root);
    cout << endl;

    return 0;
}