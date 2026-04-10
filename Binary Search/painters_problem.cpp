#include<bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int timeLimit) {
    int painters = 1;
    int currentTime = 0;

    for (int board : boards) {
        if (currentTime + board > timeLimit) {
            painters++;
            currentTime = board;
        } else {
            currentTime += board;
        }
    }

    return painters;
}

int Painters_prblm(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int requiredPainters = countPainters(boards, mid);

        if (requiredPainters <= k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout << "Minimum time to paint all boards: " << Painters_prblm(boards, k) << endl;
    return 0;
}