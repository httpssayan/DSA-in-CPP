#include <iostream>
#include <stdio.h>
using namespace std;
int secondlargest(int arr[], int n) {
    // Code Here
    int largest=arr[0];
    int secondlargest=-1;
    int i;
    for(i=1;i<n;i++){
        if(arr[i]>largest){
            secondlargest=largest;
            largest=arr[i];
        }
        else if(arr[i]<largest && arr[i]>secondlargest){
            secondlargest=arr[i];
        }
    }
    return secondlargest;
}
int main(){
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = secondlargest(arr, n);
    cout << "The second largest element in the array is: " << result << endl;
    return 0;
}