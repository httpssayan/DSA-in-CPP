#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findSmallest(TreeNode* root, int &k, int &ans){
    if(root==NULL) return;

    findSmallest(root->left,k,ans);
    k--;
    if(k==0){
        ans=root->val;
        return;
    }

    findSmallest(root->right,k,ans);
}

void findLargest(TreeNode* root, int &k, int &ans){
    if(root==NULL) return;

    findLargest(root->right,k,ans);
    k--;
    if(k==0){
        ans=root->val;
        return;
    }

    findLargest(root->left,k,ans);
}
vector<int> kLargesmall(TreeNode* root, int k) {

        int smallest = -1;
        int largest = -1;

        int k1 = k;
        int k2 = k;

        findSmallest(root, k1, smallest);
        findLargest(root, k2, largest);

        return {smallest, largest};
    }


int main(){

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

    int k1 = 3;
    int k2 = 3;

    int smallest = -1;
    int largest = -1;

    findSmallest(root, k1, smallest);
    findLargest(root, k2, largest);

    cout << "3rd Smallest: " << smallest << endl;
    cout << "3rd Largest: " << largest << endl;

    return 0;
}