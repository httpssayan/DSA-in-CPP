#include <bits/stdc++.h>
using namespace std;
int find_missing_no_in_an_array(vector<int> arr, int n){
    int sum_of_natural_no = n * (n + 1) / 2;
    int sum_of_array = 0;
    for(int i=0;i<n-1;i++){
        sum_of_array += arr[i];
    }
    return sum_of_natural_no - sum_of_array;
}
int main(){
    vector<int> arr = {1, 2, 4, 5, 6};
    int n = 6; 
    cout << find_missing_no_in_an_array(arr, n) << endl;
    return 0;
}