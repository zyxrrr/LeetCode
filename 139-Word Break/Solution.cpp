class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        vector<bool> res(len + 1, false);
        res[0] = true;
        
        for(int idx = 1; idx <= len; idx++){
            for(int sta = 0; sta < idx; sta++){
                string tmp = s.substr(sta, idx - sta);
                if(res[sta] && contain(wordDict, tmp))   {
                    res[idx] = true;
                }
            }          
            
        }
        return res[len];
        //int sta = 0, len = s.size();
        //return wordFind(s, 0, wordDict);
    }
    bool contain(vector<string>& v, string s){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == s){
                return true;
            }
        }
        return false;
    }
    /*
    bool wordFind(string s, int sta, vector<string>& wordDict){
        bool res = false;
        if(s.size() == sta){
            return true;
        }else if(sta < s.size()){
            for(int i = 0; i < wordDict.size(); i++){
                int idx = s.find(wordDict[i], sta);
                if(idx == sta){
                    res = res || wordFind(s, sta + wordDict[i].size(), wordDict);
                }
            }
            return res;
        }else{
            return false;
        }
        
    }
    */
};
