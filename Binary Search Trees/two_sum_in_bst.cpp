#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

bool findTarget(TreeNode* root, int k) {

        vector<int> arr;

        inorder(root, arr);

        int left = 0;
        int right = arr.size() - 1;

        while(left < right) {

            int sum = arr[left] + arr[right];

            if(sum == k)
                return true;

            else if(sum < k)
                left++;

            else
                right--;
        }

        return false;
    }

    int main() {

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(7);

    /*
            5
           / \
          3   6
         / \   \
        2   4   7
    */

    int k = 9;

    if(findTarget(root, k))
        cout << "Pair exists" << endl;
    else
        cout << "Pair does not exist" << endl;

    return 0;
}