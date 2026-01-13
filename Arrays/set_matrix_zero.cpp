#include <bits/stdc++.h>
using namespace std;
void set_matrix_zero(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> rows(m,0);
    vector<int> cols(n,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                rows[i]=1;
                cols[j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(rows[i]==1 || cols[j]==1){
                matrix[i][j]=0;
            }
        }
    }
    
}
int main(){
    vector<vector<int>> matrix={{1,1,1},{1,0,1},{1,1,1}};
    set_matrix_zero(matrix);
    for(auto row:matrix){
        for(auto val:row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    return 0;
}