#include<bits/stdc++.h>
using namespace std;
int nth_root_of_a_no(int n, int m){
    int low=1, high=m;
    while(low<=high){
        int mid=(low+high)/2;
        long long ans=1;
        for(int i=1;i<=n;i++){
            ans*=mid;
            if(ans>m) break;
        }
        if(ans==m) return mid;
        else if(ans<m){
            low=mid+1;
        }
        else high=mid-1;
    }
    return -1;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<nth_root_of_a_no(n,m);
    return 0;
}