class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int res = 0, tmp_cnt;
        for (int i = 0; i < nums.size(); i++){
            cnt[nums[i]] = 1;
        }
        
        for (int i = 0; i < nums.size(); i++){
            int tmp = nums[i];
            if (cnt.find(tmp-1) != cnt.end()){
                
            }else{
                tmp_cnt = 1;
                while(cnt.find(++tmp) != cnt.end()){
                    tmp_cnt++;
                }
                res = max(res, tmp_cnt);
            }
        }
        return res;
    }
};
