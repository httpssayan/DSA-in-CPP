#include<bits/stdc++.h>
using namespace std;

int main(){
    int num=5;
    int bitIndex=0;
    if(num & (1<<bitIndex)){
        cout<<"Bit is set"<<endl;
    }
    else{
        cout<<"Bit is not set"<<endl;
    }
    return 0;
}
