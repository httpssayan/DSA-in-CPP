#include <iostream>
using namespace std;

bool if_sorted(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            return false;   
        }
    }
    return true;          
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    if(if_sorted(arr, n))
        cout << "Array is sorted";
    else
        cout << "Array is not sorted";

    return 0;
}
