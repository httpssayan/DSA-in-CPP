#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>adj, vector<int>& vis){
    vis[node]=1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it, node, adj, vis)) return true;
        }
        else if(it!=parent) return true;
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>adj){
    vector<int> vis(V+1, 0);
    for(int i=1; i<=V; i++){
        if(!vis[i]){
            if(dfs(i, -1, adj, vis)) return true;
        }
    }
    return false;
}

int main(){
    int V, E;
    cin>>V>>E;
    vector<vector<int>> adj(V+1);
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(V, adj)) cout<<"Cycle detected"<<endl;
    else cout<<"No cycle detected"<<endl;
    return 0;
}