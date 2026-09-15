// floor=largest value<=target
// ceil=smallest value>=target

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int floor_bst(TreeNode* root, int key){
    int floor=-1;

    while(root!=NULL){
        if(root->val==key){
            return root->val;
        }

        if(root->val<key){
            floor=root->val;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return floor;
}

int ceil_bst(TreeNode* root, int key){
    int ceil=-1;

    while(root!=NULL){
        if(root->val==key){
            return root->val;
        }

        if(root->val > key){
            ceil=root->val;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceil;
}

int main(){

    // Create BST
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

    int key = 7;

    cout << "Floor of " << key << " = "
         << floor_bst(root, key) << endl;

    cout << "Ceil of " << key << " = "
         << ceil_bst(root, key) << endl;

    return 0;
}