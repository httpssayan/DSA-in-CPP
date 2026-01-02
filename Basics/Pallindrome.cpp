#include <iostream>
using namespace std;
bool isPalindrome(int n) {
        // code here.
        int rev_digit=0;
        int last_digit=0;
        int original=n;
        while(n>0){
            last_digit=n%10;
            rev_digit=rev_digit*10+last_digit;
            n=n/10;
        }
        return rev_digit==original;
    }
int main(){
    int n=1221;
    cout << isPalindrome(n) << endl;
    return 0;
}