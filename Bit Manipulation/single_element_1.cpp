#include<bits/stdc++.h>
using namespace std;

int get_single_element(vector<int>& arr)
{
    int result = 0;
    for(int x : arr)
        result ^= x;
    return result;
}

int main()
{
    vector<int> arr = {2,3,5,4,5,3,4};
    cout << "The single element is: " << get_single_element(arr) << endl;
    return 0;
}