class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len = nums.size();
        if (len < 1 || k < 1){return nums;}
        vector<int> left_max(len, 0);
        vector<int> right_max(len, 0);
        vector<int> res;
        left_max[0] = nums[0];
        for (int i = 1; i < len; i++){
            if (i % k == 0){
                left_max[i] = nums[i];
            }else{
                left_max[i] = max(nums[i], left_max[i-1]);
            }           
        }
        right_max[len - 1] = nums[len - 1];
        for (int i = len - 2; i >= 0; i--){
            if (i % k == k - 1){
                right_max[i] = nums[i];
            }else{
                right_max[i] = max(nums[i], right_max[i + 1]);
            }
        }
        for (int i = 0; i < len - k + 1; i++){
            res.push_back(max(right_max[i], left_max[i+k-1]));
        }
        return res;
    }
};
