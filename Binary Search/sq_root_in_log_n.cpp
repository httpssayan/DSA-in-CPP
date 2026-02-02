#include<bits/stdc++.h>
using namespace std;
int sq_root_in_log_n(int x){
    if(x<2) return x;
    int left=1, right=x/2, ans=0;
    while(left<=right){
        int mid=(left+right)/2;
        if(mid*mid<=x){
            ans=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return ans;
}
int main(){
    int x=50;
    cout << sq_root_in_log_n(x) << endl;
    return 0;
}