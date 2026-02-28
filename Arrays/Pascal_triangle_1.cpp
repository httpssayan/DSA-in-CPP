#include<bits/stdc++.h>
using namespace std;
vector <vector<int>> pascal_triangle(int n){
    vector <vector<int>> triangle;
    for (int i=0;i<n;i++){
        vector <int> row(i+1,1);
        for(int j=1;j<i;j++){
            row[j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
        triangle.push_back(row);    
    }
    return triangle;
}
int main(){
    int n=5;
    vector <vector<int>> triangle = pascal_triangle(n);
    for (int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<triangle[i][j]<<" ";
        }
        cout<<endl;
    }
}