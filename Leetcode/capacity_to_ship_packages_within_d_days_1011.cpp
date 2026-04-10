class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity){
        int load=0;
        int day=1;

        for(int w:weights){
            if(load+w>capacity){
                day++;
                load=w;
            }
            else{
                load+=w;
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=high;

        while(low<=high){
            int mid=(low+high)/2;

            if(canShip(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low=mid+1;
            }
            
        }
         return ans;
    }
   
};