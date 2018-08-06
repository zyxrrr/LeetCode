class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len <=1 ){return 0;}
        vector<int> cool(len, 0);
        vector<int> buy(len, 0);
        vector<int> sell(len, 0);
        
        buy[0] = -prices[0];
        sell[0] = INT_MIN;
        cool[0] = 0;
        for (int i = 1; i < len; i++){
            sell[i] = buy[i-1] + prices[i];
            cool[i] = max(cool[i-1], sell[i-1]);
            buy[i] = max(cool[i-1]-prices[i], buy[i-1]);
        }
        return max(sell[len-1], cool[len-1]);
    }
};
