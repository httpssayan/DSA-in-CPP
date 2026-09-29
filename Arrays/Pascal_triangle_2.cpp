#include<bits/stdc++.h>
using namespace std;

vector<int> pascal_triangle_2(int r){
    vector<int> row(1);

    for(int i=0;i<=r;i++){
        vector<int> next(i+1,1);

        for(int j=0;j<i;j++){
            next[j]=row[j-1]+row[j];
        }
        row=next;
    }
    return row;
}

int main() {
    int r;

    cout << "Enter row index: ";
    cin >> r;

    vector<int> ans = pascal_triangle_2(r);

    cout << "Pascal row: ";

    for(int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}