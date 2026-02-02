#include <bits/stdc++.h>
using namespace std;
void sort_an_array_of_0s_1s_2s(vector<int>& arr){
    int n = arr.size();
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }
        else if(arr[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }
    int index=0;
    while(count0--){
        arr[index++]=0;
    }
    while(count1--){
        arr[index++]=1;
    }
    while(count2--){
        arr[index++]=2;
    }   
}
int main() {
    vector<int> arr = {2, 0, 1, 2, 0, 1, 1, 0};
    sort_an_array_of_0s_1s_2s(arr);
    for(int x : arr) {
        cout << x << " ";
    }
    return 0;
}