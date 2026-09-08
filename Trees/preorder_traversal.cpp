#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preOrder_traversal(TreeNode* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;
    stack<TreeNode*> st;

    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();

        preOrder.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);

}
return preOrder;
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

    vector<int> ans = preOrder_traversal(root);

    cout << "Preorder: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}