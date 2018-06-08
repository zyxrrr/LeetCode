class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> tmp;
        for(int sta = 0; sta <candidates.size(); sta++){
            for(int i = sta; i < candidates.size(); ){
                int sum = sumVector(tmp);
                if(sum == target){
                    res.push_back(tmp);
                    tmp.pop_back();
                    tmp.pop_back();
                    i++;
                    //continue;
                }else if(sum < target){
                    tmp.push_back(candidates[i]);
                }else{
                    if(tmp.size() >= 2){
                        tmp.pop_back();
                        tmp.pop_back();
                        i++;
                        if(i >= candidates.size()){
                            i = sta + 1;
                        }
                    }else{
                        break;
                    }
                }
                //tmp.push_back(candidates[i]);
            }
        }
        
        return res;
    }
    
    int sumVector(vector<int> &tmp){
        int sum = 0;
        for(int i = 0; i < tmp.size(); i++){
            sum += tmp[i];
        }
        return sum;
    }
};
