class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0){return 0;}
        int len = coins.size();
        vector<int> cnt(amount+1, INT_MAX);
        cnt[0] = 0;
        
        for (int i = 1; i <= amount; i++){
            for (int j = 0; j < len; j++){
                if (i - coins[j] >= 0){
                    if (cnt[i-coins[j]] == INT_MAX){
                        
                    }else{
                        //cout << i << " " << cnt[i] << " " << j <<" "<< cnt[j] << endl;
                        cnt[i] = min(cnt[i], 1 + cnt[i-coins[j]]);
                    }                    
                }
            }
        }
        return cnt[amount] == INT_MAX ? -1 : cnt[amount];
        
        
        
    }
};
