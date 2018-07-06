class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int ele_nums = nums.size();
        int sub_nums = pow(2, ele_nums);
        vector<vector<int> > res(sub_nums, vector<int>());
        
        for(int i = 0; i < sub_nums; i++){
            for(int j = 0; j < ele_nums; j++){
                if((i >> j) & 1){
                    res[i].push_back(nums[j]);
                }
            }
        }
        return res;
    }
};
