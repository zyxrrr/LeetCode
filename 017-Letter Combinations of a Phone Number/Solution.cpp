class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        if(digits.empty()){return res;}
        res.push_back("");
        for(int i=0;i<digits.size();i++){
            int key=digits[i]-'0';
            vector<string> tmp;
            for(int j=0;j<v[key].size();j++){
                for(int k=0;k<res.size();k++){
                    tmp.push_back(res[k]+v[key][j]);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};
