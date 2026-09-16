#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* LCA_in_bst(TreeNode* root, TreeNode* p, TreeNode* q){

    while(root!=NULL){
        if(p->val<root->val && q->val<root->val){
            root=root->left;
        }
        else if(p->val>root->val && q->val>root->val){
            root=root->right;
        }
        else{
            return root;
        }
    }
    return NULL;
}

int main() {

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    /*
              8
            /   \
           3     12
          / \    / \
         1   6  10  14
    */

    TreeNode* p = root->left->left;       // 1
    TreeNode* q = root->left->right;      // 6

    

    TreeNode* lca = LCA_in_bst(root, p, q);

    cout << "LCA = " << lca->val << endl;

    return 0;
}