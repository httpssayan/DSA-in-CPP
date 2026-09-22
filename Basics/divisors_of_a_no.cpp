#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=36;
    vector<int> div;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            div.push_back(i);

            if(i!=n/i) div.push_back(n/i);
        }
    }
    sort(div.begin(),div.end());

    for(int x:div) cout<<x<<" ";

    return 0;
}