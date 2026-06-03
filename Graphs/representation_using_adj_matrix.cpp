#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

// for weighted graph, we can store the weight instead of 1 in the adjacency matrix

    cout<<"Adjacency Matrix:\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}