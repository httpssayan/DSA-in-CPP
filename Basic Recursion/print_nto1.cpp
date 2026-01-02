#include <iostream>
using namespace std;
void print_nto1(int n){
    if(n<1){
        return;
    }
    cout << n << endl;
    print_nto1(n-1);
}
int main(){
    int n=5;
    print_nto1(n);
    return 0;
}