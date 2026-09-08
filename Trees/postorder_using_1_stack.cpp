#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postOrder_one_stack(TreeNode* root) {
    vector<int> postOrder;
    if (root == NULL) return postOrder;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        postOrder.push_back(node->val);

        if (node->left) st.push(node->left);
        if (node->right) st.push(node->right);
    }

    reverse(postOrder.begin(), postOrder.end());
    return postOrder;
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

    vector<int> ans = postOrder_one_stack(root);

    cout << "Postorder: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}