#include<bits/stdc++.h>
using namespace std;

int trapping_rainwater(vector <int>& ht){
    int n=ht.size();

    int left=0;
    int right=n-1;

    int maxleft=0;
    int maxright=0;

    int water=0;

    while(left<=right){
        if(ht[left]<=ht[right]){
            if(ht[left]>=maxleft){
                maxleft=ht[left];
            }
            else{
                water+= maxleft - ht[left];
            }
            left++;
        }
        else{
            if(ht[right]>=maxright){
                maxright=ht[right];
            }
            else{
                water+= maxright - ht[right];
            }
            right--;
        }
    }
    return water;
}

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    int result =trapping_rainwater(height);

    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}