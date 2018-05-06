class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        core("",0,0,n,res);
        return res;
    }
    void core(string s,int left,int right,int n,vector<string> &res){
        if(s.size()==2*n){
            res.push_back(s);
            return;
        }
        if(left<n){
            core(s+"(",left+1,right,n,res);
        }
        if(right<left){
            core(s+")",left,right+1,n,res);
        }
    }
};
