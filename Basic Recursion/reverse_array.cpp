#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rev_arr(vector <int>& arr){
    reverse(arr.begin(), arr.end());
}
int main(){
    vector <int> arr = {1, 2, 3, 4, 5};
    rev_arr(arr);
    for(int x : arr){
        cout<< x <<" ";
    }
    return 0;
}