class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int min_ = INT_MAX, max_ = INT_MIN;
        bool flag = false;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i] > nums[i+1]){
                flag = true;
            }
            if (flag){
                min_ = min(min_, nums[i+1]);
            }
        }
        flag = false;
        for (int i = nums.size() - 1; i > 0; i--){
            if (nums[i] < nums[i-1]){
                flag = true;
            }
            if (flag){
                max_ = max(max_, nums[i-1]);
            }
        }
        int sta = 0, end = 0;
        for (sta = 0; sta < nums.size(); sta++){
            if (nums[sta] > min_){
                break;
            }
        }
        for (end = nums.size() - 1; end >= 0; end--){
            if (nums[end] < max_){
                break;
            }
        }
        return (end - sta < 0) ? 0 : end-sta+1;
    }
};
