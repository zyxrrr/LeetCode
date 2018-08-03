class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (rows < 1){return false;}
        int cols = matrix[0].size();
        if (cols < 1){return false;}
        int r = 0, c = cols - 1;
        
        while (r < rows && c >= 0){
            int tmp = matrix[r][c];
            if (tmp == target){
                return true;
            }else if (tmp < target){
                r++;
            }else{
                c--;
            }
        }
        return false;
        /*
        if (matrix[0][0] > target || matrix[rows-1][cols-1] < target){
            return false;
        }else{
            int r_low = 0;
            while(matrix[r_low][cols-1] < target){
                r_low++;
            }
            int r_high = rows - 1;
            while(matrix[r_high][0] > target){
                r_high--;
            }
            
            int c_low = 0;
            while(matrix[r_high][c_low] < target){
                c_low++;
            }
            int c_high = cols - 1;
            while(matrix[r_low][c_high] > target){
                c_high--;
            }
            for (int r = r_low; r <= r_high; r++){
                if (find(matrix,r, c_low , c_high, target)){
                    return true;
                }
            }
        }
        return false;
        */
    }
    /*
    bool find(vector<vector<int>>& matrix,int r,int l,int h, int target){
        int mid = (l+h)/2;
        if (l > h){return false;}
        if (matrix[r][mid] == target){
            return true;
        }else if(matrix[r][mid] > target){
            return find(matrix, r,l, mid - 1,target);
        }else{
            return find(matrix,r,mid + 1,h,target);
        }
    }
    */
};
