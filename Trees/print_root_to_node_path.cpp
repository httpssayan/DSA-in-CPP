#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}};   

bool find_path(TreeNode* root, int target, vector<int> &path){
    if(root == NULL) return false;
    path.push_back(root->val);
    if(root->val == target) return true;
    if(find_path(root->left, target, path) || find_path(root->right, target, path)) return true;
    path.pop_back();
    return false;
}

vector<int> path(TreeNode* root, int target){
    vector<int> ans;
    find_path(root, target, ans);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> ans = path(root, 5);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}