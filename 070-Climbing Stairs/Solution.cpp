class Solution {
public:
    int climbStairs(int n) {
        if(n == 1){return 1;}
        vector<int> cnt(n, 1);
        cnt[1] = 2;
        for(int i = 2; i < n; i++){
            cnt[i] = cnt[i -1] + cnt[i - 2];
        }
        return cnt[n - 1];
    }
};
