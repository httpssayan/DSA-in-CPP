#include <iostream>
using namespace std;
void print_1ton(int n){
    if(n<1){
        return;
    }
    print_1ton(n-1);
    cout << n << endl;
   
}
int main(){
    int n=5;
    print_1ton(n);
    return 0;
}