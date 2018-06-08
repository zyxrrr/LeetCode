class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int sta = 0, end = nums.size() - 1;
        int res;
        while(sta <= end){
            int mid = (sta + end) / 2;
            int tmp = nums[mid];
            if(tmp > target){
                end = mid - 1;
            }else if(tmp < target){
                sta = mid + 1;
            }else{
                res = mid;
                break;
            }
        }
        if(sta > end){
            res = end + 1;
        }
        return res;
    }
};
