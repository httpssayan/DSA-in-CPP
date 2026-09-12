#include<bits/stdc++.h>
using namespace std;

struct Treenode {
    int val;
    Treenode *left;
    Treenode *right;
    Treenode(int x) : val(x), left(NULL), right(NULL) {}
};

Treenode* build(vector<int>& preorder, vector<int>& inorder, int& preIndex,int inStart,int inEnd){
    if(inStart > inEnd){
        return NULL;}
    
    Treenode* root = new Treenode(preorder[preIndex]);
    preIndex++;
    int inIndex = inStart;
    while(inorder[inIndex]!=root->val){
        inIndex++;
    }
    root->left = build(preorder, inorder, preIndex, inStart, inIndex - 1);
    root->right = build(preorder, inorder, preIndex, inIndex + 1, inEnd);
    return root;
}

Treenode* buildTree(vector<int>&preorder, vector<int>&inorder){
    int preIndex = 0;

    return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
}

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Treenode* root = buildTree(preorder, inorder);

    
    return 0;
}