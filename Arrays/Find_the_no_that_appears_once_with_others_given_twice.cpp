#include <bits/stdc++.h>
using namespace std;
int no_that_appears_once(int arr[],int n){
    int xorr=0;
    for(int i=0;i<n;i++){
        xorr=xorr^arr[i];
    }
    return xorr;
}
int main(){
    int arr[]={2,3,5,4,5,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<no_that_appears_once(arr,n);
    return 0;
}