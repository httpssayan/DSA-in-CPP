#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &stalls, int cows, int mid){
    int count = 1;
    int last_postition = stalls[0];

    for (int i = 1; i < stalls.size(); i++){
        if(stalls[i] - last_postition >= mid){
            count++;
            last_postition = stalls[i];
        }
        if(count >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows){
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(canPlace(stalls, cows, mid)){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows) << endl;
    return 0;
}