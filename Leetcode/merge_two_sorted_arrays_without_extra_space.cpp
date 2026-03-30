#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, int m, int n) {
    
    int i=m-1;
    int j=n-1;
    int k=m+n-1;

    while(j>=0) {
        if(i>=0 && arr1[i]>arr2[j]) {
            arr1[k--] = arr1[i--];
        }
        else {
            arr1[k--] = arr2[j--];
        }
    }

}
int main() {
    vector<int> nums1 = {1, 3, 5, 0, 0, 0};
    vector<int> nums2 = {2, 4, 6};
    int m = 3, n = 3;
    merge(nums1, nums2,m, n);

    for (int num : nums1) cout << num << " ";
    return 0;
}