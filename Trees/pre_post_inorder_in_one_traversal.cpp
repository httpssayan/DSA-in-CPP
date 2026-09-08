#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

vector<vector<int>> getTreeTraversal(TreeNode* root){
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;

    if(root==NULL){
        return {preOrder, inOrder, postOrder};
    }

    stack<pair<TreeNode*, int>> st;

    st.push({root, 1});

    while(!st.empty()){
        auto[node, state] = st.top();
        st.pop();

        if(state==1){
            preOrder.push_back(node->data);
            st.push({node, 2});
            if(node->left!=NULL){
                st.push({node->left, 1});
            }
        }

        else if(state==2){
            inOrder.push_back(node->data);
            st.push({node, 3});
            if(node->right!=NULL){
                st.push({node->right, 1});
            }
        }

        else{
            postOrder.push_back(node->data);
        }
    }
    return {preOrder, inOrder, postOrder};
}

void printVector(vector<int> &arr){
    for (int x:arr){
            cout<<x<<" ";
        }
        cout<<endl;
    }

int main(){
    TreeNode* root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);

    root->left->left->right = new TreeNode(9);
    root->left->left->right->left = new TreeNode(1);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(6);

    root->right->right->left = new TreeNode(8);


    // Get all three traversals
    vector<vector<int>> result = getTreeTraversal(root);

    // Print results
    cout << "Preorder: ";
    printVector(result[0]);

    cout << "Inorder: ";
    printVector(result[1]);

    cout << "Postorder: ";
    printVector(result[2]);


    return 0;
}


