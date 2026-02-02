#include <iostream>
using namespace std;
bool Prime(int n) {
        if n<=1 {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
int main(){
    int n=1221;
    cout << isPalindrome(n) << endl;
    return 0;
}