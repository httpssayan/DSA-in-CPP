#include <bits/stdc++.h>
using namespace std;
int stock_buy_and_sell(vector<int> &arr){
    int min_price = INT_MAX;
    int max_profit = 0;
    for(int i : arr){
        if(i< min_price){
            min_price = i;
        }
        else {
            max_profit = max(max_profit, i - min_price);
        }
    }
    return max_profit;
}
int main() {
    vector<int> prices = {7,1,5,3,6,4};
    cout << stock_buy_and_sell(prices) << endl;
    return 0;
}