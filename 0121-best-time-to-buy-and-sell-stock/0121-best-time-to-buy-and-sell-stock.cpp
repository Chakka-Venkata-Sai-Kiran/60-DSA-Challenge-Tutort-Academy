class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> sell(prices.size(),0);
        int SuffixMax = prices.back();
        for(int i = prices.size() - 1; i >= 0; i--){
            SuffixMax = max(SuffixMax, prices[i]);
            sell[i] = SuffixMax;
        }
        int maxprofit = 0;
        for(int i = 0; i < prices.size(); i++)
            maxprofit = max(maxprofit, sell[i] - prices[i]);
        return maxprofit;
    }
};