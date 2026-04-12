#include<bits/stdc++.h>
using namespace std;

bool Search_in_2d_matrix_2(vector<vector<int>> &arr, int target){
    int m= arr.size();
    int n= arr[0].size();

    int row=0;    int col= n-1;

    while(row<m && col>=0){
        if(arr[row][col]==target) return true;
        else if(arr[row][col]>target) col--;
        else row++;
    }
    return false;
}

int main(){
    vector<vector<int>> arr={{1,4,7,11,15},
                             {2,5,8,12,19},
                             {3,6,9,16,22},
                             {10,13,14,17,24},
                             {18,21,23,26,30}};
    int target=5;
    cout<<Search_in_2d_matrix_2(arr,target);
}