#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}};

TreeNode* lca(TreeNode*root, TreeNode* p, TreeNode* q){
    if(root == NULL) return NULL;
    if(root == p || root == q) return root;
    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);
    if(left && right) return root;
    return left ? left : right;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode* p = root->left->left; // Node with value 4
    TreeNode* q = root->left->right; // Node with value 5

    TreeNode* lca_node = lca(root, p, q);
    if (lca_node) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca_node->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}