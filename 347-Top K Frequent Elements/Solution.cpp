class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        vector<vector<int> > buk(nums.size()+1);
        for (auto ele : cnt){
            buk[ele.second].push_back(ele.first);
        }
        vector<int> ans;
        for (int i = buk.size() - 1; i >=0 && ans.size() < k; i--){
            for (int tmp : buk[i]){
                ans.push_back(tmp);
                if (ans.size() == k){
                    break;
                }
            }            
        }
        return ans;
    }
};
