#include<bits/stdc++.h>
using namespace std;

int row_with_max_1s(vector<vector<int>> & arr){
    int n= arr.size();
    int m= arr[0].size();
    int max_row=-1;
    int row=0, col=m-1;
    while(row<n && col>=0){
        if(arr[row][col]==1){
            max_row=row;
            col--;
        }
        else{
            row++;
        }
    }
return max_row;
}

int main(){
    vector<vector<int>> arr={{0, 0, 0, 1},
                            {0, 1, 1, 1},
                            {1, 1, 1, 1},
                            {0, 0, 0, 0}};
    cout<<row_with_max_1s(arr);}