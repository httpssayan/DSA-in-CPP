class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price= INT_MAX;
        int maxprofit= 0;
        for(int i : prices){
            if(i<min_price){
                min_price=i;
            }
            else{
                maxprofit=max(maxprofit,i-min_price);
            }
        }
        return maxprofit;
    }
};