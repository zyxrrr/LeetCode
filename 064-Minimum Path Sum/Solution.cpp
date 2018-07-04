class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> tmp(cols, 0);
        vector<vector<int> > dp(rows, tmp);
        dp[0][0] = grid[0][0];
        for(int r = 1; r < rows; r++){
            dp[r][0] = grid[r][0] + dp[r - 1][0];
        }
        for(int c = 1; c < cols; c++){
            dp[0][c] = grid[0][c] + dp[0][c - 1];
        }
        for(int r = 1; r < rows; r++){
            for(int c = 1; c < cols; c++){
                dp[r][c] = min(dp[r - 1][c], dp[r][c - 1]) + grid[r][c];
            }
        }
        return dp[rows - 1][cols - 1];
        /*
        int res = -1, sum = 0;
        core(grid, 0, 0, rows, cols, res, sum);
        return res;
        */
    }
    
    /*
    void core(vector<vector<int>>& grid, int r, int c, int rows, int cols, int& res, int sum){
        if(r >= rows || c >= cols){
            return;
        }
        sum += grid[r][c];
        if(r == rows - 1 && c == cols -1){
            if(res == -1){res = sum;}
            if(sum < res){res = sum;}
        }
        core(grid, r + 1, c, rows, cols, res, sum);
        core(grid, r, c + 1, rows, cols, res, sum);
    }
    */
};
