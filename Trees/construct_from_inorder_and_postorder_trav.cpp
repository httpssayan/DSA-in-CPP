#include<bits/stdc++.h>
using namespace std;

struct Treenode {
    int val;
    Treenode *left;
    Treenode *right;
    Treenode(int x) : val(x), left(NULL), right(NULL) {}
};

Treenode* build(vector<int>& postorder, vector<int>& inorder, int& postIndex,int inStart,int inEnd){
    if(inStart > inEnd){
        return NULL;}
    
    Treenode* root = new Treenode(postorder[postIndex]);
    postIndex--;
    int inIndex = inStart;
    while(inorder[inIndex]!=root->val){
        inIndex++;
    }
    
    root->right = build(postorder, inorder, postIndex, inIndex + 1, inEnd);
    root->left = build(postorder, inorder, postIndex, inStart, inIndex - 1);
    return root;
}

Treenode* buildTree(vector<int>&postorder, vector<int>&inorder){
    int postIndex = postorder.size() - 1;

    return build(postorder, inorder, postIndex, 0, inorder.size() - 1);
}

int main(){
    vector<int> postorder = {9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};

    Treenode* root = buildTree(postorder, inorder);

    
    return 0;
}