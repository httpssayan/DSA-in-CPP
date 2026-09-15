#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert_into_bst(TreeNode*root, int val){
    if(!root) return new TreeNode(val);
    if(val<root->val){
        root->left=insert_into_bst(root->left,val);
    }
    else{
        root->right=insert_into_bst(root->right,val);
    }
    return root;
}

int main(){

    TreeNode* root = NULL;

    root = insert_into_bst(root, 8);
    root = insert_into_bst(root, 3);
    root = insert_into_bst(root, 12);
    root = insert_into_bst(root, 1);
    root = insert_into_bst(root, 6);
    root = insert_into_bst(root, 10);
    root = insert_into_bst(root, 14);

    // Insert another node
    root = insert_into_bst(root, 5);

    cout << "BST created successfully." << endl;

    return 0;
}