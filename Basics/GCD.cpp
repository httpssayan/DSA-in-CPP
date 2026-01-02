#include <iostream>
using namespace std;
int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b) a=a%b;
        else b=b%a;
        if(a==0) return b;
        else if(b==0) return a;
    }
}
int main(){
    int n1=50, n2=55;
    cout << "GCD: " << gcd(n1, n2) << endl;
    return 0;
}