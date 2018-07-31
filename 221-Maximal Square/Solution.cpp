class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        //cout << rows;
        if (rows < 1){return 0;}
        int cols = matrix[0].size();
        //cout <<cols;
        if (cols < 1){return 0;}
        vector<int> tmp(cols, 0);
        vector<vector<int> > size(rows, tmp);
        int max = 0;
        
        for (int i = 0; i < rows; i++){
            if ('1' == matrix[i][0]){
                size[i][0] = 1;
                max = 1;
                //cout<< "----";
            }
        }
        
        for (int i = 0; i < cols; i++){
            if ('1' == matrix[0][i]){
                size[0][i] = 1;
                max = 1;
                //cout << "---------";
            }
        }
        
        for (int r = 1; r < rows; r++){
            for (int c = 1; c < cols; c++){
                if ('1' == matrix[r][c]){
                    size[r][c] = min(min(size[r][c - 1], size[r - 1][c]), size[r - 1][c - 1]) + 1;
                    //cout << r << " " << c << " " << size[r][c]<<endl;
                }                
                if (size[r][c] > max){max = size[r][c];}
            }
        }
        
        return max * max;
    }
};
