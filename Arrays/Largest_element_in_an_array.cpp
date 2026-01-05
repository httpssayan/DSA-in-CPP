#include <iostream>
#include <stdio.h>
using namespace std;
int largest(int arr[], int n) {
    // Code Here
    int l=arr[0];
    int i;
    for(i=1;i<n;i++){
        if(arr[i]>l){
            l=arr[i];
        }
    }
    return l;
}
int main(){
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = largest(arr, n);
    cout << "The largest element in the array is: " << result << endl;
    return 0;
}