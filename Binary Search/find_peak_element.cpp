#include<bits/stdc++.h>
using namespace std;

vector<int> find_peak_grid(vector<vector<int>>& mat){
    int m= mat.size();
    int n= mat[0].size();

    int low=0, high=n-1;

    while(low<=high){
        int mid = low + (high-low)/2;
        int max_row=0;
        for(int i=0; i<m; i++){
            if(mat[i][mid]>mat[max_row][mid]){
                max_row=i;
            }
        }

        int left= mid-1>=0? mat[max_row][mid-1]:INT_MIN;
        int right= mid+1<n? mat[max_row][mid+1]:INT_MIN;

        if(mat[max_row][mid]>left && mat[max_row][mid]>right){
            return {max_row, mid};
        }
        else if(left>mat[max_row][mid]){
            high= mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return {-1, -1};
}

int main(){
    vector<vector<int>> mat = {{1, 4}, {3, 2}};
    vector<int> peak = find_peak_grid(mat);
    cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
    return 0;
}