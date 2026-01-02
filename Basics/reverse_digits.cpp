#include <iostream>
using namespace std;
int reverseDigits(int n) {
        int rev_num=0;
        int lastdigit=0;
        while(n>0){
            lastdigit=n%10;
            rev_num=rev_num*10+lastdigit;
            n=n/10;
        }
        return rev_num;
    }
int main(){
    int n=1234;
    cout << "Number of digits: " << reverseDigits(n) << endl;
    return 0;
}