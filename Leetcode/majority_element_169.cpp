class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int element;
        for(int num:nums){
            if(count==0){
                count=1;
                element=num;
            }
            else if(element==num){
                count++;
            }
            else{
                count--;
            }
        }
        int count1=0;
        for(int num:nums){
            if(element==num){
                count1++;
            }
        }
        if(count1>n/2){
            return element;
        }
        return -1;
    }
};