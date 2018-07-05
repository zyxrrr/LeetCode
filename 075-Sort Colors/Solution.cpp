class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int idx_red = 0, idx_white = 0;
        while(idx_white < len){
            if(nums[idx_white] == 2){
                swap(nums[idx_white], nums[len - 1]);
                len--;
            }else if(nums[idx_white] == 1){
                idx_white++;
            }else{
                swap(nums[idx_white], nums[idx_red]);
                idx_white++;
                idx_red++;
            }
        }
    }
};
