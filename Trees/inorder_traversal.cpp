#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inOrderTraversal(TreeNode* root){
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        ans.push_back(curr->val);
        curr = curr->right;
    }
    return ans;
}
int main()
{
    //        1
    //       /
    //      4
    //     / \
    //    4   2

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(4);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);

    vector<int> ans = inOrderTraversal(root);

    cout << "Inorder: ";

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}