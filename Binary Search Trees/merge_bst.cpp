#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, vector<int> &ans){
    if(root==NULL) return;

    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}

vector<int> mergeBST(TreeNode* root1, TreeNode* root2){
    vector<int> arr1;
    vector<int> arr2;

    inorder(root1,arr1);
    inorder(root2,arr2);

    vector<int> ans;

    int i=0,j=0;

    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<=arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }

        else{
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i < arr1.size()) {
        ans.push_back(arr1[i]);
        i++;
    }

    while(j < arr2.size()) {
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main() {

    // First BST
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(6);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(4);

    /*
            5
           / \
          3   6
         / \
        2   4
    */

    // Second BST
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->right->right = new TreeNode(7);
    root2->right->right->left = new TreeNode(6);

    /*
            2
           / \
          1   3
               \
                7
               /
              6
    */

    vector<int> ans = mergeBST(root1, root2);

    cout << "Merged BSTs: ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}