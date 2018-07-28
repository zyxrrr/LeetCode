class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows < 1){return 0;}
        int cols = grid[0].size();
        if(rows < 1 || cols <1){return 0;}
        int ans = 0;      
        
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if('1' == grid[r][c]){
                    isLand(grid, r, c);
                    ans++;
                }                
            }
        }     
        return ans;
        
    }
    
    void isLand(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0'){
            return;
        }
        if(grid[r][c] == '1'){            
            grid[r][c] = '0';
            isLand(grid, r + 1, c);
            isLand(grid, r, c + 1);
            isLand(grid, r, c - 1);
            isLand(grid, r - 1, c);
        }
        
    }
};

