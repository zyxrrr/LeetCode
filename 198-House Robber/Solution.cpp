class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len < 1){
            return 0;
        }
        vector<int> pre(len, 0);//not robber this
        vector<int> now(len, 0);//robber this
        now[0] = nums[0];
        for(int i = 1; i <len; i++){
            pre[i] = max(now[i-1], pre[i-1]);
            now[i] = pre[i-1] + nums[i];
        }
        return max(pre[len-1], now[len-1]);
    }
};
