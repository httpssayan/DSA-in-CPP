#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root, int& d){
    if(root == NULL) return 0;
    int left = height(root->left, d);
    int right = height(root->right, d);

    d = max(d, left + right+1);

    return 1+max(left, right);
}

int diameter(TreeNode* root) {
    int d = 0;
    height(root, d);
    return d;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the tree: " << diameter(root) << endl;

    return 0;
}