class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2){return 0;}
        int buy = prices[0];
        int sell,max = prices[1] - buy;
        for(int i = 1; i < len; i++){
            int profit = prices[i] - buy;
            if(profit < 0){
                buy = prices[i];
            }
            if(profit > max){
                max = profit;
            }
        }
        if(max < 0){max = 0;}
        return max;
    }
};
