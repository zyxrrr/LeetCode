class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.size();
        if(len < 1){return false;}
        int sta = word[0];
        int rows = board.size(), cols = board[0].size();
        vector<bool> tmp(cols, false);
        vector<vector<bool> > flags(rows, tmp);
        bool finded = false;
        
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (sta == board[r][c]){
                    finded = find(word, 0,  board,  flags, r, c);
                    if(finded == true){
                        return true;
                    }
                }
            }
        }
        return finded;
    }
    
    bool find(string &word, int idx, vector<vector<char>>& board, vector<vector<bool> > flags, int r, int c){        
        if(r >= 0 && c >= 0 && r < board.size() && c < board[0].size() && flags[r][c] == false){
            if(word[idx] == board[r][c]){
                flags[r][c] = true;
                if(idx == word.size() - 1){
                    //finded = true;
                    return true;
                }else{
                    bool res;
                    res = find(word, idx + 1,  board,  flags,  r + 1, c);
                    if(!res){res = find(word, idx + 1, board,  flags,  r , c + 1);}
                    if(!res){res = find(word, idx + 1,  board,  flags,  r , c - 1);}
                    if(!res){res = find(word, idx + 1,  board,  flags,  r - 1, c);}
                    return res;
                }
            }else{
                return false;
            }
        }else{
            return false;
        }
         
        /*
        if(idx == len - 1){
            if(word[idx] == board[r][c]){
                finded = true;
                return;
            }else{
                return;
            }
        }else{
            
        }
        */
    }
};
