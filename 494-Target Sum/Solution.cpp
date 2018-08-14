class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (nums.empty()){return 0;}
        return find(nums,0,S);
        /*
        queue<int> q;
        queue<int> tmp;
        int cnt = 0;
        if (nums.empty()){
            return cnt;
        }
        q.push(nums[0]);
        q.push(-nums[0]);
        for (int i = 1; i < nums.size(); i++){
            while (!q.empty()){
                int val = q.front();
                q.pop();
                tmp.push(val + nums[i]);
                tmp.push(val - nums[i]);
            }
            q.swap(tmp);
        }
        while (!q.empty()){
            if (q.front() == S){
                cnt++;
            }
            q.pop();
        }
        return cnt;
        */
    }
    int find(vector<int> &nums,int idx,int S){
        if (idx == nums.size()){
            if (S == 0){return 1;}
            else{return 0;}
        }else{
            return find(nums,idx + 1, S - nums[idx]) + find(nums,idx + 1, S + nums[idx]);
        }
    }
};
