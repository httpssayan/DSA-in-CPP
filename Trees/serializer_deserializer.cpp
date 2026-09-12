#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void serializer(TreeNode* root, string &s){
    if(!root){
        s+= "#,";
        return;
    }
    s+= to_string(root->val) + ",";
    serializer(root->left, s);
    serializer(root->right, s);
}

string serialize(TreeNode* root) {
    string s;
    serializer(root, s);
    return s;
}

TreeNode* deserializer(stringstream &ss){
    string str;
    getline(ss, str, ',');
    if(str == "#") return NULL;
    
    TreeNode* root = new TreeNode(stoi(str));
    root->left = deserializer(ss);
    root->right = deserializer(ss);
    
    return root;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    return deserializer(ss);
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserializedRoot = deserialize(serialized);
    string reserialized = serialize(deserializedRoot);
    cout << "Reserialized: " << reserialized << endl;

    return 0;
}