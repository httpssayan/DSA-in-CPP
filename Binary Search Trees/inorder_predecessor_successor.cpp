#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int,int> predecessor_successor(TreeNode* root, int key) {

    int predecessor = -1;
    int successor = -1;

    TreeNode* curr = root;

    while(curr != NULL) {

        if(curr->val == key) {

            // Find predecessor
            if(curr->left != NULL) {
                TreeNode* temp = curr->left;

                while(temp->right != NULL)
                    temp = temp->right;

                predecessor = temp->val;
            }

            // Find successor
            if(curr->right != NULL) {
                TreeNode* temp = curr->right;

                while(temp->left != NULL)
                    temp = temp->left;

                successor = temp->val;
            }

            break;
        }

        else if(key < curr->val) {
            // Current node can be successor
            successor = curr->val;
            curr = curr->left;
        }

        else {
            // Current node can be predecessor
            predecessor = curr->val;
            curr = curr->right;
        }
    }

    return {predecessor, successor};
}

int main() {

    TreeNode* root = new TreeNode(8);

    root->left = new TreeNode(3);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int key = 8;

    pair<int, int> result = predecessor_successor(root, key);

    cout << "Predecessor: " << result.first << endl;
    cout << "Successor: " << result.second << endl;

    return 0;
}