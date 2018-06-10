class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        core(candidates, target, res, tmp, 0);
        return res;
    }
    
    void core(vector<int>& candidates, int target, vector<vector<int> > &res, vector<int> &tmp, int idx){
        if(target == 0){
            res.push_back(tmp);
            return;
        }
        for(int i = idx; i < candidates.size() && target >= candidates[i]; i++){
            tmp.push_back(candidates[i]);
            core(candidates, target - candidates[i], res, tmp, i);
            tmp.pop_back();
        }
    }
};
