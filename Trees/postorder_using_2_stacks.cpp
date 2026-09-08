#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postOrder(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while(!st1.empty()){
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);

        if(node->left) st1.push(node->left);
        if(node->right) st1.push(node->right);
    }
    while(!st2.empty()){
        ans.push_back(st2.top()->val);
        st2.pop();
    }
    return ans;
}
int main()
{
    // Creating the tree
    //
    //              4
    //            /   \
    //           2     5
    //          /     / \
    //         3     7   6
    //          \       /
    //           9     8
    //          /
    //         1

    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);

    root->left->left->right = new TreeNode(9);
    root->left->left->right->left = new TreeNode(1);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);

    root->right->right->left = new TreeNode(8);

    vector<int> ans = postOrder(root);

    cout << "Postorder: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}