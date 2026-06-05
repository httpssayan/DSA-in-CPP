#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();

    grid[row][col]=0;

    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};

    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1){
            dfs(nrow,ncol,grid);
        }
    }
}

int number_of_enclaves(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || i==n-1 || j==m-1){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                }
            }
        }
    }

    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<vector<int>> grid = {{0,0,0,0},
                                {1,0,1,0},
                                {0,1,1,0},
                                {0,0,0,0}};

    cout << number_of_enclaves(grid) << endl;

    return 0;
}