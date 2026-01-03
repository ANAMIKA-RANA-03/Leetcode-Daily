class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0; // we need to maximise profit and for that we need to minimise the cost price and maximise sell price
        for(int i = 1 ; i < prices.size(); i++){
            mini = min( mini, prices[i]);

            profit = max(profit, prices[i] - mini);
        }
        return profit;
    }
};