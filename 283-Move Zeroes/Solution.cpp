class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            int tmp = nums[i];
            if (0 == tmp){
                cnt++;
            }else{
                nums[i-cnt] = tmp;
            }
        }
        for (int i = nums.size() - 1; i >= 0 && cnt > 0; i--, cnt--){
            nums[i] = 0;
        }
        
    }
};
