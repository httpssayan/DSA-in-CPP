#include<bits/stdc++.h>
using namespace std;

int reqStations(double dist, vector<int>& arr){
    int count = 0;
    for(int i = 1; i < arr.size(); i++){
        double gap = arr[i] - arr[i-1];
        count += ceil(gap / dist) - 1;
    }
    return count;
}

double minimise_max_distance(vector<int>& arr, int k){
    double low = 0, high = 0;

    for(int i = 1; i < arr.size(); i++){
        high = max(high, (double)(arr[i] - arr[i-1]));
    }

    while(high - low > 1e-6){
        double mid = low + (high - low) / 2.0;
        if(reqStations(mid, arr) > k){
            low = mid;
        }
        else{
            high = mid;
        }
    }

    return high;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;

    double ans = minimise_max_distance(arr, k);
    cout << ans << "\n";

    return 0;
}