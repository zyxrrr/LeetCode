class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool> flags(len, false);
        flags[0] = true;
        if (len == 1){
            return true;
        }
        for (int i = 0; i < len - 1; i++){
            int tmp = nums[i];
            bool flag = flags[i];
            if (!flag){
                continue;
            }
            if(tmp > 0){
                for (int j = i + 1; j < i + tmp + 1 && j < len; j++){
                    flags[j] = true;
                }
            }else{
                flags[i] = false;
            }            
        }
        
        
        return flags[len - 1];
        
    }
};
