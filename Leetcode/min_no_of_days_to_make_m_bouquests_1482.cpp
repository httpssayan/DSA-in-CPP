class Solution {
public:
    bool possible(vector<int>&arr, int mid, int m, int k){
        int n=arr.size();
        int count=0;
        int bouquets=0;
        for(int i=0;i<n;i++){
            if (arr[i]<=mid){
                count++;
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }
            else{
                count=0;
            }
        }
        return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long total=1LL*m*k;
        if(total>n) return -1;
        int res=-1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if (possible(bloomDay, mid, m, k)){
                res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};