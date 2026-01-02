#include <iostream>
using namespace std;
void print_name(string name,int count,int n){
    if(count==n){
        return;
    }
    cout << name << endl;
    print_name(name,count+1,n);
}
int main(){
    string name="JCB";
    int n=3;
    print_name(name,0,n);
    return 0;
}