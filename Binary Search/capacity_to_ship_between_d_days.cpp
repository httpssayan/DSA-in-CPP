#include<bits/stdc++.h>
using namespace std;

bool canShip(vector<int>& weights, int days, int capacity) {
    int load = 0;
    int day=1;
    for(int w: weights) {
        if(load + w > capacity) {
            day++;
            load = w;
        }
        else{
        load += w;}
    }
    return day <= days;
}

int ship_sithin_days(vector<int>& weights, int days) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    int ans=right;
    
    while(left <= right) {
        int mid = (left+right)/2;
        if(canShip(weights, days, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;
    cout << ship_sithin_days(weights, days) << endl;
    return 0;
}