class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lsf = INT_MAX;
        int profit=0,profitday=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<lsf){
                lsf = prices[i];
            }
            profitday = prices[i] - lsf;
            if(profit < profitday){
                profit = profitday;
            }
        }
        return profit;
    }
};