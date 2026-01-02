#include <iostream>
using namespace std;
int sumoffirstn(int n){
    if(n<1){
        return 0;
    }
    return n+sumoffirstn(n-1);
}
int main(){
    int n=5;
    cout << sumoffirstn(n) << endl;
    return 0;
}