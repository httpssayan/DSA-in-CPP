#include<bits/stdc++.h>
using namespace std;
vector<int> rearange_array(vector<int> &arr){
    int n=arr.size();
    vector<int> result(n);
    int pos=0;
    int neg=1;
    for(int i : arr){
        if(i>0){
            result[pos]=i;
            pos+=2;
        }
        else{
            result[neg]=i;
            neg+=2;
        }
    }
    return result;
}
int main(){
    vector<int> arr={3,1,-2,-5,2,-4};
    vector<int> result=rearange_array(arr);
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}