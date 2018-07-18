class Solution {
public:
    int numTrees(int n) {
        vector<int> res(n + 1, 0);
        res[0] = 1;
        res[1] = 1;
        
        for(int num = 2; num <= n; num++){
            for(int root_num = 1; root_num <= num; root_num++){
                res[num] += res[root_num - 1] * res[num - root_num];
            }
        }
        
        return res[n];
    }    
};
