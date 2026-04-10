class Solution {
public:
    int Partition(vector <int>& nums, int mid){
        int par=1;
        int sum=0;
        for(int num: nums){
            if(sum+num> mid){
                par++;
                sum=num;
            }
            else{
                sum+=num;
            }
        }
        return par;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(), nums.end());
        int high=accumulate(nums.begin(), nums.end(), 0);
        int result=high;

        while(low<=high){
            int mid=(low+high)/2;
            int part=Partition(nums, mid);

            if(part<=k){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};