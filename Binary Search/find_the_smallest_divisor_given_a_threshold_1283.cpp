class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold) return -1;
        int low=1, high=*max_element(nums.begin(),nums.end());
        int res;
        while(low<=high){
            int mid=(low+high)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil(double(nums[i])/mid);
            }
            if(sum<=threshold){
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