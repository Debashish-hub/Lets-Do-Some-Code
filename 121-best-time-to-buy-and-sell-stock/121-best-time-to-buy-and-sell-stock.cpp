class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        int m = prices[0];
        
        for (int i = 1; i < prices.size(); i++){
            m = min(prices[i], m); 
            profit = max(profit, prices[i] - m);
        }
        
        return profit;
    }
};