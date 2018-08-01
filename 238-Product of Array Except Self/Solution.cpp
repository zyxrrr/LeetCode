class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 1);
        for (int i = 1; i < len; i++){
            res[i] = res[i - 1]*nums[i - 1];
            //cout << res[i] <<endl;
        }
        int right = 1;
        for (int i = len - 1; i >= 0; i--){
            res[i] = right*res[i];
            right *= nums[i];
            //cout << res[i] <<endl;
        }
        return res;
    }
};
