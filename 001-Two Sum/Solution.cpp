class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int tmp=target-nums[i];
            map<int,int>::iterator it = hash.find(tmp);
            if (it != hash.end() && i!=it->second){
                res.push_back(i);
                res.push_back(it->second);
                break;
            }    
        }
        return res;
    }
};
