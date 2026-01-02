#include <iostream>
using namespace std;
int count_digits(int n){
    int count=0;
    while(n>0){
        n=n/10;
        count++;
    }
    return count;
}
int main(){
    int n=1234;
    cout << "Number of digits: " << count_digits(n) << endl;
    return 0;
}