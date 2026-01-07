#include <bits/stdc++.h>
using namespace std;
int Max_consecutive_ones(int arr[],int n){
    int count=0;
    int maximum=0;
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            count++;
            maximum=max(maximum,count);
        }
        else{
            count=0;
        }
    }
    return maximum;
}
int main() {
    int arr[] = {1, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << Max_consecutive_ones(arr, n) << endl;
    return 0;
}