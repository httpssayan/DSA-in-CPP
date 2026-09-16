#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert_into_bst(TreeNode* root, int val) {
    if(!root)
        return new TreeNode(val);

    if(val < root->val)
        root->left = insert_into_bst(root->left, val);
    else
        root->right = insert_into_bst(root->right, val);

    return root;
}

TreeNode* delete_from_bst(TreeNode* root, int key) {

    if(root == NULL)
        return NULL;

    if(key < root->val) {
        root->left = delete_from_bst(root->left, key);
    }
    else if(key > root->val) {
        root->right = delete_from_bst(root->right, key);
    }
    else {

        // No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Only right child
        if(root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // Only left child
        if(root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Two children
        TreeNode* temp = root->right;

        while(temp->left != NULL)
            temp = temp->left;

        root->val = temp->val;

        root->right = delete_from_bst(root->right, temp->val);
    }

    return root;
}

void inorder(TreeNode* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = NULL;

    root = insert_into_bst(root, 8);
    root = insert_into_bst(root, 3);
    root = insert_into_bst(root, 12);
    root = insert_into_bst(root, 1);
    root = insert_into_bst(root, 6);
    root = insert_into_bst(root, 10);
    root = insert_into_bst(root, 14);

    cout << "Before deletion: ";
    inorder(root);

    root = delete_from_bst(root, 3);

    cout << "\nAfter deletion: ";
    inorder(root);

    return 0;
}