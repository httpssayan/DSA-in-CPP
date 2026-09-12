#include<bits/stdc++.h>
using namespace std;

struct Treenode {
    int val;
    Treenode* left;
    Treenode* right;
    Treenode(int x) : val(x), left(NULL), right(NULL) {}
};

void markParents(Treenode* root, unordered_map<Treenode*, Treenode*>& parent_track, Treenode* target) {
    queue<Treenode*> q;
    q.push(root);
    while(!q.empty()) {
        Treenode* current = q.front();
        q.pop();
        if(current->left) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}

vector<int> distanceK(Treenode* root, Treenode* target, int k) {
    unordered_map<Treenode*, Treenode*> parent_track;
    markParents(root, parent_track, target);
    
    unordered_map<Treenode*, bool> visited;
    queue<Treenode*> q;
    q.push(target);
    visited[target] = true;
    int curr_level = 0;
    
    while(!q.empty()) {
        int size = q.size();
        if(curr_level == k) break;
        curr_level++;
        for(int i = 0; i < size; i++) {
            Treenode* current = q.front();
            q.pop();
            if(current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]) {
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    
    vector<int> result;
    while(!q.empty()) {
        Treenode* current = q.front();
        q.pop();
        result.push_back(current->val);
    }
    
    return result;
}

int main() {
    // Example usage:
    Treenode* root = new Treenode(3);
    root->left = new Treenode(5);
    root->right = new Treenode(1);
    root->left->left = new Treenode(6);
    root->left->right = new Treenode(2);
    root->right->left = new Treenode(0);
    root->right->right = new Treenode(8);
    root->left->right->left = new Treenode(7);
    root->left->right->right = new Treenode(4);

    Treenode* target = root->left; // Node with value 5
    int k = 2;

    vector<int> result = distanceK(root, target, k);
    
    cout << "Nodes at distance " << k << " from target node " << target->val << ": ";
    for(int val : result) {
        cout << val << " ";
    }
    
    return 0;
}