#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void markParents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent,
                     TreeNode*& target,
                     int targetValue) {

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node->val == targetValue)
                target = node;

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    int minTime(TreeNode* root, int targetValue) {

        if (root == NULL)
            return 0;

        unordered_map<TreeNode*, TreeNode*> parent;

        TreeNode* target = NULL;

        // Step 1: Store parents and find target
        markParents(root, parent, target, targetValue);

        // Step 2: BFS from target
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int time = 0;

        while (!q.empty()) {

            int size = q.size();
            bool burnedNewNode = false;

            for (int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Left child
                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                    burnedNewNode = true;
                }

                // Right child
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                    burnedNewNode = true;
                }

                // Parent
                if (parent[node] && !visited[parent[node]]) {
                    visited[parent[node]] = true;
                    q.push(parent[node]);
                    burnedNewNode = true;
                }
            }

            if (burnedNewNode)
                time++;
        }

        return time;
    }

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int targetValue = 5;
    int result = minTime(root, targetValue);
    cout << "Minimum time to burn the tree from target " << targetValue << ": " << result << endl;

    return 0;
}