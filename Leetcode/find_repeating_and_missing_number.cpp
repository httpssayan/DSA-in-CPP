#include<bits/stdc++.h>
using namespace std;

vector<int> finding(vector<int> &arr){
    long long n=arr.size();
    long long Sn=(n*(n+1))/2;
    long long S2n=(n*(n+1)*(2*n+1))/6;
    long long S=0;
    long long S2=0;
    for(int i=0;i<n;i++){
        S+=arr[i];
        S2+=(long long)arr[i]*arr[i];
    }
    long long x=S-Sn;
    long long y=(S2-S2n)/x;
     x=(x+y)/2;
    
     y=y-x;
    return {(int)x,(int)y};

}

int main() {
    vector<int> nums = {3, 1, 2, 5, 4, 6, 7, 5};
    
    

    vector<int> result = finding(nums);
    
    cout << "The repeating and missing numbers are: {" << result[0] << ", " << result[1] << "}\n";
    
    return 0;
}