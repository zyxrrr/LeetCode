class Solution {
public:
    int maxProduct(vector<int>& nums) {        
        int len = nums.size();
        if(len < 1){return 0;}
        
        vector<int> positive (len, 0);
        vector<int> minus(len, 0);
        minus[0] = nums[0];
        positive[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < len; i++){
            positive[i] = max(max(nums[i]*positive[i-1], nums[i]*minus[i-1]), nums[i]);
            minus[i] = min(min(nums[i]*positive[i-1], nums[i]*minus[i-1]), nums[i]);
            res = max(res, positive[i]);
        }
        return res;
        
    }
};
