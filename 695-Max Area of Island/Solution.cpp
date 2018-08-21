class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int num,max = 0;
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                //tmp = grid[r][c];
                if (grid[r][c] == 1){
                    num = 0;
                    core(grid, r, c, rows, cols, num);
                    if (num > max){max = num;}
                }
            }
        }
        return max;
    }
    void core(vector<vector<int>>& grid, int r, int c, int rows, int cols, int &num){
        if (r >=0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1){
            grid[r][c] = -1;
            num++;
            core(grid, r-1, c, rows, cols, num);
            core(grid, r+1, c, rows, cols, num);
            core(grid, r, c-1, rows, cols, num);
            core(grid, r, c+1, rows, cols, num);
        }
        return;
    }
};
