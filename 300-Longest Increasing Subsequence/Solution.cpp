class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()){return 0;}
        int maxans = 1, maxtmp = 0;
        vector<int> ans(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++){
            maxtmp = 0;
            for (int j = 0; j < i; j++){                
                if (nums[j] < nums[i]){
                    maxtmp = max(maxtmp , ans[j]);
                }
            }
            //cout << "a[i]: " << ans[i] << "maxtmp : " << maxtmp <<endl;
            ans[i] += maxtmp; 
            //cout << ans[i] <<endl;
            if (ans[i] > maxans){
                maxans = ans[i];
            }
        }
        return maxans;
    }
};
