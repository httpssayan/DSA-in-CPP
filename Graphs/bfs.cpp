#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>>& adj){
    vector<int> visited(adj.size(), 0);
    queue<int> q;

    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    bfs(1, adj);

    return 0;
}