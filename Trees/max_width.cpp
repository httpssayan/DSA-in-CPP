#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int max_width(TreeNode* root){
    if (root==NULL) return 0;
    long long ans=0;
    queue<pair<TreeNode*, long long>> q;
    q.push({root, 0});

    while(!q.empty()){
        int size=q.size();

        long long first=q.front().second;
        long long last=first;

        for(int i=0;i<size;i++){
            auto [node, index]=q.front();
            q.pop();
            if(i==0) first=index;

            if(i==size-1) last=index;

            index=index-first;
            if(node->left) q.push({node->left, 2*index+1});
            if(node->right) q.push({node->right, 2*index+2});

        }
        ans=max(ans, last-first+1);
    }
    return ans;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(6);

    cout<<max_width(root)<<endl;

    return 0;
}