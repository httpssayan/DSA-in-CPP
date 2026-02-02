#include <bits/stdc++.h>
using namespace std;
vector<int> spiral_traversal_of_matrix(vector<vector<int>>& matrix){
    int m=matrix.size();
    int n=matrix[0].size();
    vector<int> result;
    int top=0, bottom=m-1, left=0, right=n-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            result.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            result.push_back(matrix[i][right]);
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                result.push_back(matrix[i][left]);
            }
            left++;
        }   
    
}
return result;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> result = spiral_traversal_of_matrix(matrix);
    for(int num : result) {
        cout << num << " ";
    }
    return 0;
}
