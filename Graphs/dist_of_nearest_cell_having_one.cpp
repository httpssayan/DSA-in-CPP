#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dist_of_nearest_cell_having_one(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>,int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;

        for(int k=0; k<4; k++){
            int nrow = row + dr[k];
            int ncol = col + dc[k];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return dist;
}
int main(){
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> result = dist_of_nearest_cell_having_one(grid);

    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[0].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}