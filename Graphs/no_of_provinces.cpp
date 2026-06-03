#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
   vis[node] = 1;

        int n = adj.size();

        for(int neighbour = 0; neighbour < n; neighbour++)
        {
            if(adj[node][neighbour] == 1
               && !vis[neighbour])
            {
                dfs(neighbour, adj, vis);
            }
        }
    }

int number_of_provinces(vector<vector<int>>& adj){
    int n=adj.size();
    vector<int> vis(n, 0);
    int count=0;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            count++;
            dfs(i, adj, vis);
        }
    }
    return count;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>adj[i][j];
        }
    }
    cout<<number_of_provinces(adj)<<endl;
    return 0;
}