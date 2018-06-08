class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int sta = 0, end = nums.size() - 1;
        while(sta <= end){
            int idx = (sta + end) / 2;
            if(nums[idx] < target){
                sta = idx + 1;
            }else if(nums[idx] > target){
                end = idx - 1;
            }else{
                int left = searchIdxLeft(nums, target, sta, idx);
                int right = searchIdxRight(nums, target, idx, end);
                res.push_back(left);
                res.push_back(right);
                break;
            }
        }
        if(sta > end){
            res.push_back(-1);
            res.push_back(-1);
        }
        return res;
    }
    
    int searchIdxLeft(vector<int>& nums, int target, int sta, int end){
        //int sta = 0, end = nums.size() - 1;
        while(sta <= end){
            int idx = (sta + end) / 2;
            if(nums[idx] < target){
                sta = idx + 1;
            }else if(nums[idx] > target){
                end = idx - 1;
            }else{
                if(sta == end){
                    return sta;
                }else{
                    return searchIdxLeft(nums, target, sta, idx);
                }                
                //break;
            }
        }
    }
    
    int searchIdxRight(vector<int>& nums, int target, int sta, int end){
        //int sta = 0, end = nums.size() - 1;
        while(sta <= end){
            int idx = (sta + end) / 2;
            if(nums[idx] < target){
                sta = idx + 1;
            }else if(nums[idx] > target){
                end = idx - 1;
            }else{
                if(sta == end){
                    return sta;
                }else{
                    if(searchIdxRight(nums, target, idx + 1, end) == -1){
                        return idx;
                    }else{
                        return searchIdxRight(nums, target, idx + 1, end);
                    }
                    
                }
            }                
        }
        
        if(sta > end){
            return -1;
        }
    }
};
